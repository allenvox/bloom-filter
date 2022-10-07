#include <stdio.h>
#include "bloom.h"

int main() {
    BloomFilter *f = bloom_init(10);
    bloom_insert(f, "apple");
    bloom_lookup(f, "apple");
    return 0;
}