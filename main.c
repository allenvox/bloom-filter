#include "bloom.h"
#include "hashtab.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

double wtime() {
    struct timespec time;
    clock_gettime(CLOCK_REALTIME, &time);
    return ((double)time.tv_sec + (double)time.tv_nsec / 100000000);
}

void filter_inserting(BloomFilter *f) {
    bloom_insert(f, "apple");
    bloom_insert(f, "coconut");
    bloom_insert(f, "watermelon");
    bloom_insert(f, "pomegranate");
    bloom_insert(f, "pineapple");
    bloom_insert(f, "grapes");
    bloom_insert(f, "orange");
    bloom_insert(f, "banana");
    bloom_insert(f, "melon");
    bloom_insert(f, "dragonfruit");
    bloom_insert(f, "strawberry");
    bloom_insert(f, "blueberry");
    bloom_insert(f, "blackberry");
    bloom_insert(f, "cherry");
    bloom_insert(f, "apricot");
    bloom_insert(f, "kiwi");
    bloom_insert(f, "lime");
    bloom_insert(f, "peach");
    bloom_insert(f, "lemon");
    bloom_insert(f, "pear");
}

void ht_inserting(listnode **hashtab, int size, int *collisions) {
    int v = 1;
    hashtab_add(hashtab, "apple", v++, size, collisions);
    hashtab_add(hashtab, "coconut", v++, size, collisions);
    hashtab_add(hashtab, "watermelon", v++, size, collisions);
    hashtab_add(hashtab, "pomegranate", v++, size, collisions);
    hashtab_add(hashtab, "pineapple", v++, size, collisions);
    hashtab_add(hashtab, "grapes", v++, size, collisions);
    hashtab_add(hashtab, "orange", v++, size, collisions);
    hashtab_add(hashtab, "banana", v++, size, collisions);
    hashtab_add(hashtab, "melon", v++, size, collisions);
    hashtab_add(hashtab, "dragonfruit", v++, size, collisions);
    hashtab_add(hashtab, "strawberry", v++, size, collisions);
    hashtab_add(hashtab, "blueberry", v++, size, collisions);
    hashtab_add(hashtab, "blackberry", v++, size, collisions);
    hashtab_add(hashtab, "cherry", v++, size, collisions);
    hashtab_add(hashtab, "apricot", v++, size, collisions);
    hashtab_add(hashtab, "kiwi", v++, size, collisions);
    hashtab_add(hashtab, "lime", v++, size, collisions);
    hashtab_add(hashtab, "peach", v++, size, collisions);
    hashtab_add(hashtab, "lemon", v++, size, collisions);
    hashtab_add(hashtab, "pear", v++, size, collisions);
}

void ht_deletion(listnode **hashtab, int size) {
    hashtab_delete(hashtab, "apple", size);
    hashtab_delete(hashtab, "coconut", size);
    hashtab_delete(hashtab, "watermelon", size);
    hashtab_delete(hashtab, "pomegranate", size);
    hashtab_delete(hashtab, "pineapple", size);
    hashtab_delete(hashtab, "grapes", size);
    hashtab_delete(hashtab, "orange", size);
    hashtab_delete(hashtab, "banana", size);
    hashtab_delete(hashtab, "melon", size);
    hashtab_delete(hashtab, "dragonfruit", size);
    hashtab_delete(hashtab, "strawberry", size);
    hashtab_delete(hashtab, "blueberry", size);
    hashtab_delete(hashtab, "blackberry", size);
    hashtab_delete(hashtab, "cherry", size);
    hashtab_delete(hashtab, "apricot", size);
    hashtab_delete(hashtab, "kiwi", size);
    hashtab_delete(hashtab, "lime", size);
    hashtab_delete(hashtab, "peach", size);
    hashtab_delete(hashtab, "lemon", size);
    hashtab_delete(hashtab, "pear", size);
}

void filter_searching_in(BloomFilter *f) {
    bloom_lookup(f, "apple");
    bloom_lookup(f, "coconut");
    bloom_lookup(f, "watermelon");
    bloom_lookup(f, "pomegranate");
    bloom_lookup(f, "pineapple");
    bloom_lookup(f, "grapes");
    bloom_lookup(f, "orange");
    bloom_lookup(f, "banana");
    bloom_lookup(f, "melon");
    bloom_lookup(f, "dragonfruit");
    bloom_lookup(f, "strawberry");
    bloom_lookup(f, "blueberry");
    bloom_lookup(f, "blackberry");
    bloom_lookup(f, "cherry");
    bloom_lookup(f, "apricot");
    bloom_lookup(f, "kiwi");
    bloom_lookup(f, "lime");
    bloom_lookup(f, "peach");
    bloom_lookup(f, "lemon");
    bloom_lookup(f, "pear");
}

void ht_searching_in(listnode **hashtab, int size) {
    hashtab_lookup(hashtab, "apple", size);
    hashtab_lookup(hashtab, "coconut", size);
    hashtab_lookup(hashtab, "watermelon", size);
    hashtab_lookup(hashtab, "pomegranate", size);
    hashtab_lookup(hashtab, "pineapple", size);
    hashtab_lookup(hashtab, "grapes", size);
    hashtab_lookup(hashtab, "orange", size);
    hashtab_lookup(hashtab, "banana", size);
    hashtab_lookup(hashtab, "melon", size);
    hashtab_lookup(hashtab, "dragonfruit", size);
    hashtab_lookup(hashtab, "strawberry", size);
    hashtab_lookup(hashtab, "blueberry", size);
    hashtab_lookup(hashtab, "blackberry", size);
    hashtab_lookup(hashtab, "cherry", size);
    hashtab_lookup(hashtab, "apricot", size);
    hashtab_lookup(hashtab, "kiwi", size);
    hashtab_lookup(hashtab, "lime", size);
    hashtab_lookup(hashtab, "peach", size);
    hashtab_lookup(hashtab, "lemon", size);
    hashtab_lookup(hashtab, "pear", size);
}

void filter_searching_out(BloomFilter *f) {
    bloom_lookup(f, "tomato");
    bloom_lookup(f, "aubergine");
    bloom_lookup(f, "potato");
    bloom_lookup(f, "cucumber");
    bloom_lookup(f, "cabbage");
    bloom_lookup(f, "pumpkin");
    bloom_lookup(f, "corn");
    bloom_lookup(f, "onion");
    bloom_lookup(f, "garlic");
    bloom_lookup(f, "cauliflower");
    bloom_lookup(f, "pepper");
    bloom_lookup(f, "ginger");
    bloom_lookup(f, "beans");
    bloom_lookup(f, "peas");
    bloom_lookup(f, "carrot");
    bloom_lookup(f, "raddish");
    bloom_lookup(f, "broccoli");
    bloom_lookup(f, "turnip");
    bloom_lookup(f, "mint");
    bloom_lookup(f, "spinach");
}

void ht_searching_out(listnode **hashtab, int size) {
    hashtab_lookup(hashtab, "tomato", size);
    hashtab_lookup(hashtab, "aubergine", size);
    hashtab_lookup(hashtab, "potato", size);
    hashtab_lookup(hashtab, "cucumber", size);
    hashtab_lookup(hashtab, "cabbage", size);
    hashtab_lookup(hashtab, "pumpkin", size);
    hashtab_lookup(hashtab, "corn", size);
    hashtab_lookup(hashtab, "onion", size);
    hashtab_lookup(hashtab, "garlic", size);
    hashtab_lookup(hashtab, "cauliflower", size);
    hashtab_lookup(hashtab, "pepper", size);
    hashtab_lookup(hashtab, "ginger", size);
    hashtab_lookup(hashtab, "beans", size);
    hashtab_lookup(hashtab, "peas", size);
    hashtab_lookup(hashtab, "carrot", size);
    hashtab_lookup(hashtab, "raddish", size);
    hashtab_lookup(hashtab, "broccoli", size);
    hashtab_lookup(hashtab, "turnip", size);
    hashtab_lookup(hashtab, "mint", size);
    hashtab_lookup(hashtab, "spinach", size);
}

int main() {
    double start, end, t;
    int col = 0;
    printf("Initialization:\n");
    getchar();
    int size = 20;
    BloomFilter *f = bloom_init(size, 0.01); // create a filter of 10 elements with falsepositive probability 1%
    listnode **hashtab = malloc(sizeof(listnode*) * size);
    hashtab_init(hashtab, size);
    
    printf("\nAdding fruits to Bloom filter:\n");
    getchar();
    start = wtime();
    filter_inserting(f);
    end = wtime();
    t = end - start;
    printf("Took %.3f seconds\n", t);

    printf("\nAdding fruits to hash table with closed addressation:\n");
    getchar();
    start = wtime();
    ht_inserting(hashtab, size, &col);
    end = wtime();
    t = end - start;
    printf("Took %.3f seconds, made %d collisions\n", t, col);

    printf("\nLookup elements that already are in Bloom filter:\n");
    getchar();
    start = wtime();
    filter_searching_in(f);
    end = wtime();
    t = end - start;
    printf("Took %.3f seconds\n", t);

    printf("\nLookup elements that already are in hash table:\n");
    getchar();
    start = wtime();
    ht_searching_in(hashtab, size);
    end = wtime();
    t = end - start;
    printf("Took %.3f seconds\n", t);

    printf("\nLookup elements that are not in Bloom filter:\n");
    getchar();
    start = wtime();
    filter_searching_out(f);
    end = wtime();
    t = end - start;
    printf("Took %.3f seconds\n", t);

    printf("\nLookup elements that are not in hash table:\n");
    getchar();
    start = wtime();
    ht_searching_out(hashtab, size);
    end = wtime();
    t = end - start;
    printf("Took %.3f seconds\n", t);

    bloom_free(f);
    ht_deletion(hashtab, size);
    free(hashtab);
    getchar();
    
    /*char words[200000][8];
    FILE *inp = fopen("words.txt", "r");
    for(int i = 0; !feof(inp); i++) {
        char r = (char)fgetc(inp);
        int k = 0;
        while (r != '\n' && !feof(inp)) {
            words[i][k++] = r;
            r = (char)fgetc(inp);
        }
        words[i][k] = '\0';
    }

    size = 100000;
    BloomFilter *f2 = bloom_init(size, 0.05);
    listnode **hashtab2 = malloc(sizeof(listnode*) * size);
    hashtab_init(hashtab2, size);

    printf("\nInserting 100000 words in Bloom filter:\n");
    start = wtime();
    for(int i = 0; i < 100000; i++) {
        bloom_insert(f2, words[i]);
    }
    end = wtime();
    t = end - start;
    printf("Took %.3f seconds\n", t);
    
    printf("\nInserting 100000 words in hash table:\n");
    start = wtime();
    for(int i = 0; i < 100000; i++) {
        hashtab_add(hashtab2, words[i], i, size, &col);
    }
    end = wtime();
    t = end - start;
    printf("Took %.3f seconds, made %d collisions\n", t, col);

    printf("\nLooking up 100000 words that are in Bloom filter:\n");
    start = wtime();
    for(int i = 0; i < 100000; i++) {
        bloom_lookup(f2, words[i]);
    }
    end = wtime();
    t = end - start;
    printf("Took %.3f seconds\n", t);
    
    printf("\nLooking up 100000 words that are in hash table:\n");
    start = wtime();
    for(int i = 0; i < 100000; i++) {
        hashtab_lookup(hashtab2, words[i], size);
    }
    end = wtime();
    t = end - start;
    printf("Took %.3f seconds\n", t);
    
    printf("\nLooking up 100000 words that are not in Bloom filter:\n");
    start = wtime();
    for(int i = 100000; i < 200000; i++) {
        bloom_lookup(f2, words[i]);
    }
    end = wtime();
    t = end - start;
    printf("Took %.3f seconds\n", t);
    
    printf("\nLooking up 100000 words that are not in hash table:\n");
    start = wtime();
    for(int i = 100000; i < 200000; i++) {
        hashtab_lookup(hashtab2, words[i], size);
    }
    end = wtime();
    t = end - start;
    printf("Took %.3f seconds\n", t);

    bloom_free(f2);
    hashtab_free(hashtab2, size);*/
    return 0;
}