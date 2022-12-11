#include "bloom.h"
#include "bits.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define BITS_FOR_TYPE 8.0 // for uint8_t
#define FNV_32_PRIME 16777619
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

void bloom_free(BloomFilter *f) {
    free(f->bits);
}

int bloom_optimalFilterSize(unsigned int n, double p)                       // n - number of elements
{                                                                           // p - probability of false positive
    return (unsigned int) ceil(-((double) n * log(p)) / (log(2) * log(2)));
}

int bloom_optimalHashNumber(unsigned int n, unsigned int m)         // n - number of elements
{                                                                   // m - filter size
    return (unsigned int) ceil(((double) m / (double) n) * log(2));
}

BloomFilter *bloom_init(unsigned int number_of_elements, double falsepositive_probability)
{
    printf("%s elements = %d\n", bloom_prefix, number_of_elements);
    printf("%s falsepositive probability = %.1f%%\n", bloom_prefix, falsepositive_probability*100);

    BloomFilter *f = malloc(sizeof(BloomFilter));
    if(f == NULL) {
        return NULL;
    }

    f->m = bloom_optimalFilterSize(number_of_elements, falsepositive_probability);
    int arraySize = (int) ceil(f->m / BITS_FOR_TYPE);
    printf("%s optimal filter size = %d (%d bytes)\n", bloom_prefix, f->m, arraySize);

    f->bits = malloc(sizeof(uint8_t) * arraySize);
    if(f->bits == NULL) {
        return NULL;
    }
    for(int i = 0; i < arraySize; i++) {
        f->bits[i] = 0;
    }

    f->k = bloom_optimalHashNumber(number_of_elements, f->m);
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
    for(int i = 0; i < f->k; i++) {
        set_bit(f->bits, bloom_FNVHash(s, i) % f->m);
    }
    printf("%s inserted '%s'\n", bloom_prefix, s);
}