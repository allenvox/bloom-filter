#include "bloom.h"
#include "bits.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define BITS_FOR_TYPE 8.0 // for uint8_t
#define FNV_32_PRIME 16777619
#define FALSEPOSITIVE_PROBABILITY 0.01 // 1%

char *bloom_prefix = "[bloom filter]";

unsigned int bloom_FNVHash(const char *key, int i) // fnv-1a
{
    unsigned int hash_value = 2166136261 - i; // for different hash functions
    while(*key) {
        hash_value ^= (unsigned int)*key++;
        hash_value *= FNV_32_PRIME;
    }
    return hash_value;
}

int bloom_optimalFilterSize(unsigned int n, double p)                       // n - number of elements
{                                                                           // p - probability of false positive
    return (unsigned int) ceil(-((double) n * log(p)) / (log(2) * log(2)));
}

int bloom_optimalHashNumber(unsigned int n, unsigned int m)         // n - number of elements
{                                                                   // m - filter size
    return (unsigned int) ceil(((double) m / (double) n) * log(2));
}

BloomFilter *bloom_init(unsigned int n)
{
    printf("%s n (elements) = %d\n", bloom_prefix, n);
    BloomFilter *f = malloc(sizeof(BloomFilter));
    if(f != NULL) {
        printf("%s malloc *f - success\n", bloom_prefix);
    }
    f->m = bloom_optimalFilterSize(n, FALSEPOSITIVE_PROBABILITY);
    printf("%s m (optimal filter size) = %d\n", bloom_prefix, f->m);
    int arraySize = (int) ceil(f->m / BITS_FOR_TYPE);
    f->bits = malloc(sizeof(uint8_t) * arraySize);
    if(f->bits != NULL) {
        printf("%s malloc f->bits - success\n", bloom_prefix);
    }
    for(int i = 0; i < arraySize; i++) {
        f->bits[i] = 0;
    }
    f->k = bloom_optimalHashNumber(n, f->m);
    printf("%s k (optimal hash functions number) = %d\n", bloom_prefix, f->k);
    return f;
}

int bloom_lookup(BloomFilter *f, const char *s)
{
    for(int i = 0; i < f->k; i++) {
        if(get_bit(f->bits, bloom_FNVHash(s, i) % f->m) == 0) {
            printf("%s '%s' is not in filter\n", bloom_prefix, s);
            return 0;
        }
    }
    printf("%s '%s' is probably in filter\n", bloom_prefix, s);
    return 1;
}

void bloom_insert(BloomFilter *f, const char *s)
{
    if(!bloom_lookup(f, s)){
        for(int i = 0; i < f->k; i++) {
            set_bit(f->bits, bloom_FNVHash(s, i) % f->m);
        }
        printf("%s successfully inserted '%s'\n", bloom_prefix, s);
    }
}