#include "bloom.h"
#include "hashtab.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

double wtime() {
    struct timespec time;
    clock_gettime(CLOCK_REALTIME, &time);
    return ((double)time.tv_sec + (double)time.tv_nsec * 1E-6);
}

void filter_inserting(BloomFilter *f) {
    printf("\nAdding fruits to Bloom filter:\n");
    double t = wtime();
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
    t = wtime() - t;
    printf("Took %.3f seconds\n", t);
}

void ht_inserting(listnode **hashtab, int size) {
    printf("\nAdding fruits to hash table with closed addressation:\n");
    int collisions = 0;
    double t = wtime();
    int v = 1;
    hashtab_add(hashtab, "apple", v++, size, &collisions);
    hashtab_add(hashtab, "coconut", v++, size, &collisions);
    hashtab_add(hashtab, "watermelon", v++, size, &collisions);
    hashtab_add(hashtab, "pomegranate", v++, size, &collisions);
    hashtab_add(hashtab, "pineapple", v++, size, &collisions);
    hashtab_add(hashtab, "grapes", v++, size, &collisions);
    hashtab_add(hashtab, "orange", v++, size, &collisions);
    hashtab_add(hashtab, "banana", v++, size, &collisions);
    hashtab_add(hashtab, "melon", v++, size, &collisions);
    hashtab_add(hashtab, "dragonfruit", v++, size, &collisions);
    hashtab_add(hashtab, "strawberry", v++, size, &collisions);
    hashtab_add(hashtab, "blueberry", v++, size, &collisions);
    hashtab_add(hashtab, "blackberry", v++, size, &collisions);
    hashtab_add(hashtab, "cherry", v++, size, &collisions);
    hashtab_add(hashtab, "apricot", v++, size, &collisions);
    hashtab_add(hashtab, "kiwi", v++, size, &collisions);
    hashtab_add(hashtab, "lime", v++, size, &collisions);
    hashtab_add(hashtab, "peach", v++, size, &collisions);
    hashtab_add(hashtab, "lemon", v++, size, &collisions);
    hashtab_add(hashtab, "pear", v++, size, &collisions);
    t = wtime() - t;
    printf("Took %.3f seconds, made %d collisions\n", t, collisions);
}

void filter_searching_in(BloomFilter *f) {
    printf("\nLookup elements that already are in Bloom filter:\n");
    double t = wtime();
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
    t = wtime() - t;
    printf("Took %.3f seconds\n", t);
}

void ht_searching_in(listnode **hashtab, int size) {
    printf("\nLookup elements that already are in hash table:\n");
    double t = wtime();
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
    t = wtime() - t;
    printf("Took %.3f seconds\n", t);
}

void filter_searching_out(BloomFilter *f) {
    printf("\nLookup elements that are not in Bloom filter:\n");
    double t = wtime();
    bloom_lookup(f, "tomato");
    bloom_lookup(f, "aubergine");
    bloom_lookup(f, "potato");
    bloom_lookup(f, "cucumber");
    bloom_lookup(f, "cabbage");
    bloom_lookup(f, "pumpkin");
    bloom_lookup(f, "corn");
    bloom_lookup(f, "onion");
    t = wtime() - t;
    printf("Took %.3f seconds\n", t);
}

void ht_searching_out(listnode **hashtab, int size) {
    printf("\nLookup elements that are not in hash table:\n");
    double t = wtime();
    hashtab_lookup(hashtab, "tomato", size);
    hashtab_lookup(hashtab, "aubergine", size);
    hashtab_lookup(hashtab, "potato", size);
    hashtab_lookup(hashtab, "cucumber", size);
    hashtab_lookup(hashtab, "cabbage", size);
    hashtab_lookup(hashtab, "pumpkin", size);
    hashtab_lookup(hashtab, "corn", size);
    hashtab_lookup(hashtab, "onion", size);
    t = wtime() - t;
    printf("Took %.3f seconds\n", t);
}

int main() {
    int size = 20;
    BloomFilter *f = bloom_init(size, 0.01); // create a filter of 10 elements with falsepositive probability 1%
    listnode **hashtab = malloc(sizeof(listnode*) * size);
    hashtab_init(hashtab, size);

    filter_inserting(f);
    ht_inserting(hashtab, size);

    filter_searching_in(f);
    ht_searching_in(hashtab, size);

    filter_searching_out(f);
    ht_searching_out(hashtab, size);

    bloom_free(f);
    return 0;
}