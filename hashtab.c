#include "hashtab.h"
#include "bloom.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *hashtab_prefix = "[hash table]";

void hashtab_init(listnode **hashtab, int size) {
    for (int i = 0; i < size; i++) {
        hashtab[i] = NULL;
    }
    printf("%s elements = 20\n", hashtab_prefix);
}

void hashtab_add(listnode **hashtab, char *key, int value, int size, int *collision) {
    int index = bloom_FNVHash(key, 0) % size;
    listnode *node = malloc(sizeof(*node));
    if(node != NULL) { // malloc succeeded
        node->key = key;
        node->value = value;
        if(hashtab[index] != NULL) {
            *collision += 1;
            node->next = hashtab[index]->next;
            hashtab[index]->next = node;
        } else {
            node->next = hashtab[index];
            hashtab[index] = node;
        }
        //printf("%s inserted '%s':'%d'\n", hashtab_prefix, key, value);
    } else {
        printf("Error while allocating memory\n");
    }
}

listnode *hashtab_lookup(listnode **hashtab, char *key, int size) {
    listnode *node;
    int index = bloom_FNVHash(key, 0) % size;
    for (node = hashtab[index]; node != NULL; node = node->next) {
        if (strcmp(node->key, key) == 0) {
            //printf("%s '%s' found\n", hashtab_prefix, key);
            return node;
        }
    }
    //printf("%s '%s' not found\n", hashtab_prefix, key);
    return NULL;
}

void hashtab_delete(listnode **hashtab, char *key, int size) {
    listnode *node, *prev = NULL;
    int index = bloom_FNVHash(key, 0) % size;
    for (node = hashtab[index]; node != NULL; node = node->next) {
        if (strcmp(node->key, key) == 0) {
            if (prev == NULL) {
                hashtab[index] = node->next;
            } else {
                prev->next = node->next;
            }
            free(node);
            return;
        }
        prev = node;
    }
}

listnode *list_createnode(char *key, int value) {
    listnode *p = malloc(sizeof(*p));
    if (p != NULL) {
        p->key = key;
        p->value = value;
        p->next = NULL;
    }
    return p;
}

listnode *list_addfront(listnode *list, char *key, int value) {
    listnode *newnode = list_createnode(key, value);
    if (newnode != NULL) {
        newnode->next = list;
        return newnode;
    }
    return list;
}

listnode *list_lookup(listnode *list, char *key) {
    for (; list != NULL; list = list->next) {
        if (strcmp(list->key, key) == 0) {
            return list;
        }
    }
    return NULL; // if not found
}

listnode *list_delete(listnode *list, char *key) {
    listnode *p, *prev = NULL;
    for (p = list; p != NULL; p = p->next) {
        if (strcmp(p->key, key) == 0) {
            if (prev == NULL) {
                list = p->next; /* Удаляем голову */
            } else {
                prev->next = p->next; /* Есть элемент слева */
                free(p); /* Освобождаем память */
                return list; /* Указатель на новую голову */
            }
        }
        prev = p; /* Запоминаем предыдущий элемент */
    }
    return NULL; // not found
}