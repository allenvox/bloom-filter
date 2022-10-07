#pragma once

#include <inttypes.h>

typedef struct {
    uint8_t *bits;
    int m; // filter size
    int k; // number of hash functions
} BloomFilter;

unsigned int fnv_hash(char *key, int i);
int bloom_optimalFilterSize(unsigned int n, double p);
int bloom_optimalHashNumber(unsigned int n, unsigned int m);
BloomFilter *bloom_init(unsigned int n);
int bloom_lookup(BloomFilter *f, const char *s);
void bloom_insert(BloomFilter *f, const char *s);