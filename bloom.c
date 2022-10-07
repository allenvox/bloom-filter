#include "bloom.h"
#include "bits.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *bloom_prefix = "[bloom filter]";

unsigned int bloom_FNVHash(const char *key, int i)
{
    unsigned int hash_value = 0x811c9dc5 - i;
    while(*key) {
        hash_value ^= (unsigned int)*key++;
        hash_value *= 0x01000193; // fnv_32_prime
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
    printf("%s n = %d\n", bloom_prefix, n);
    BloomFilter *f = malloc(sizeof(BloomFilter));
    if(f != NULL) {
        printf("%s malloc *f - success\n", bloom_prefix);
    }
    f->m = bloom_optimalFilterSize(n, 0.005);
    printf("%s m = %d\n", bloom_prefix, f->m);
    int arraySize = (int) ceil(f->m / 8.0);
    f->bits = malloc(sizeof(uint8_t) * arraySize);
    if(f->bits != NULL) {
        printf("%s malloc f->bits - success\n", bloom_prefix);
    }
    for(int i = 0; i < arraySize; i++) {
        f->bits[i] = 0;
    }
    f->k = bloom_optimalHashNumber(n, f->m);
    printf("%s k = %d\n", bloom_prefix, f->k);
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
    if(bloom_lookup(f, s)) {
        printf("%s probably inserted '%s' before\n", bloom_prefix, s);
    } else {
        for(int i = 0; i < f->k; i++) {
            set_bit(f->bits, bloom_FNVHash(s, i) % f->m);
        }
        printf("%s successfully inserted '%s'\n", bloom_prefix, s);
    }
}