#pragma once
#include <inttypes.h>

typedef struct {
    uint8_t *bits;
    int m; // filter size
    int k; // number of hash functions
} BloomFilter;

unsigned int bloom_FNVHash(const char *key, int i);
int bloom_optimalFilterSize(unsigned int n, double p);
int bloom_optimalHashNumber(unsigned int n, unsigned int m);
BloomFilter *bloom_init(unsigned int number_of_elements, double falsepositive_probability);
int bloom_lookup(BloomFilter *f, const char *s);
void bloom_insert(BloomFilter *f, const char *s);
void bloom_free(BloomFilter *f);