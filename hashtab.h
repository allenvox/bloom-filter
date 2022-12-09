#pragma once

typedef struct listnode {
    char *key;
    int value;
    struct listnode *next;
} listnode;

void hashtab_init(listnode **hashtab, int size);
void hashtab_add(listnode **hashtab, char *key, int value, int size, int *collision);
listnode *hashtab_lookup(listnode **hashtab, char *key, int size);
void hashtab_delete(listnode **hashtab, char *key, int size);
listnode *list_createnode(char *key, int value);
listnode *list_addfront(listnode *list, char *key, int value);
listnode *list_lookup(listnode *list, char *key);
listnode *list_delete(listnode *list, char *key);