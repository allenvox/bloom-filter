#include "bloom.h"

int main() {
    BloomFilter *f = bloom_init(10, 0.01); // create a filter of 10 elements with falsepositive probability 1%
    for(int i = 0; i < 2; i++) {
        bloom_insert(f, "apple");
        bloom_insert(f, "coconut");
        bloom_insert(f, "aubergine");
        bloom_insert(f, "pomegranate");
        bloom_insert(f, "pineapple");
        bloom_insert(f, "grapes");
        bloom_insert(f, "orange");
        bloom_insert(f, "banana");
        bloom_insert(f, "potato");
        bloom_insert(f, "cucumber");
    }
    bloom_lookup(f, "tomato");
    return 0;
}