#ifndef FNV_HASH_H
#define FNV_HASH_H

#include <string>
unsigned long long fnv1_64(std::string data);
unsigned int fnv1_32(std::string data);

#endif