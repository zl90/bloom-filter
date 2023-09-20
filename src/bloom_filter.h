#ifndef BLOOM_FILTER_H
#define BLOOM_FILTER_H

#include <string>
#include <vector>

class BloomFilter
{
private:
    int length;
    std::vector<bool> bits;

public:
    BloomFilter(int len)
    {
        this->length = len;
        for (int i = 0; i < len; i++)
        {
            bits.push_back(false);
        }
    }

    bool isMember(std::string);
    void add(std::string);
};

#endif