#include "bloom.h"
#include <stdio.h>

int main() {
    printf("\nInitialization of filter:\n");
    BloomFilter *f = bloom_init(20, 0.01); // create a filter of 10 elements with falsepositive probability 1%
    printf("\nAdding fruits:\n");
    for(int i = 0; i < 2; i++) {
        if(i == 1) {
            printf("\nChecking fruits:\n");
        }
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
    printf("\nChecking vegetables:\n");
    bloom_lookup(f, "tomato");
    bloom_lookup(f, "aubergine");
    bloom_lookup(f, "potato");
    bloom_lookup(f, "cucumber");
    bloom_lookup(f, "cabbage");
    bloom_lookup(f, "pumpkin");
    bloom_lookup(f, "corn");
    bloom_lookup(f, "onion");
    return 0;
}