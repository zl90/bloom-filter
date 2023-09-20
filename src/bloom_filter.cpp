#include "bloom_filter.h"
#include <string>
#include "../lib/murmur.h"
#include "../lib/fnv_hash.h"

bool BloomFilter::isMember(std::string str)
{
    // hash the string
    uint32_t hash = murmur3_32(str, 0);
    uint32_t hash2 = fnv1_32(str);

    // resize the hash to fit our bitset
    uint32_t resizedHash = hash % this->length;
    uint32_t resizedHash2 = hash2 % this->length;

    // check the bitmap for corresponding matches
    return this->bits[resizedHash] && this->bits[resizedHash2];
}

void BloomFilter::add(std::string str)
{
    // hash the string
    uint32_t hash = murmur3_32(str, 0);
    uint32_t hash2 = fnv1_32(str);

    // resize the hash to fit our bitset
    uint32_t resizedHash = hash % this->length;
    uint32_t resizedHash2 = hash2 % this->length;

    // update our bitmap
    this->bits[resizedHash] = true;
    this->bits[resizedHash2] = true;
}