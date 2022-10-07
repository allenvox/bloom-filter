#include "bits.h"
#include <inttypes.h>

void set_bit(uint8_t A[], int k)
{
    int i = k / 8;         // index in the array A
    int pos = k % 8;       // bit position in A[i]
    unsigned int flag = 1; // flag 00001
    flag = flag << pos;    // flag shifted k positions (e.g. 00100)
    A[i] = A[i] | flag;    // set the bit at k position in A[i] to 1
}

void clear_bit(uint8_t A[], int k)
{
    int i = k / 8;
    int pos = k % 8;
    unsigned int flag = 1;
    flag = flag << pos;
    flag = ~flag;          // negative (e.g. 11011)
    A[i] = A[i] & flag;
}

uint8_t get_bit(uint8_t A[], int k)
{
    int i = k / 8;
    int pos = k % 8;
    unsigned int flag = 1;
    flag = flag << pos;
    return ((A[i] & flag) != 0); // compare xxXxx & 00100 - getting needed bit
}