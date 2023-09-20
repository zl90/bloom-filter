#include "../lib/test_utils.h"
#include "../lib/murmur.h"
#include "bloom_filter.h"

int main()
{
    int len = 20;
    BloomFilter bloomFilter(len);
    bloomFilter.add("hello");
    bloomFilter.add("world");
    bloomFilter.add("foo");
    bloomFilter.add("bar");

    expect("test1", bloomFilter.isMember("hello"), true);
    expect("test2", bloomFilter.isMember("world"), true);
    expect("test3", bloomFilter.isMember("foo"), true);
    expect("test4", bloomFilter.isMember("bar"), true);
    expect("test5", bloomFilter.isMember("barry"), false);
    bloomFilter.add("barry");
    expect("test6", bloomFilter.isMember("barry"), true);
    expect("test7", bloomFilter.isMember("leonardo"), false);
    expect("test8", bloomFilter.isMember("fred"), false);
    expect("test9", bloomFilter.isMember("fred2"), false);
    expect("test10", bloomFilter.isMember("fred3"), false);
    expect("test11", bloomFilter.isMember("fred4"), false);
    expect("test12", bloomFilter.isMember("fred5"), false);
    expect("test13", bloomFilter.isMember("fred6"), false);
    expect("test14", bloomFilter.isMember("fred7"), false);
    expect("test15", bloomFilter.isMember("fred8"), false);
    expect("test16", bloomFilter.isMember("fred9"), false);
    expect("test17", bloomFilter.isMember("fred0"), false);
    expect("test18", bloomFilter.isMember("fred11"), false);
    expect("test19", bloomFilter.isMember("fred12"), false);
    expect("test20", bloomFilter.isMember("fred13"), false);
    expect("test21", bloomFilter.isMember("fred14"), false);
    expect("test22", bloomFilter.isMember("fred15"), false);
    expect("test23", bloomFilter.isMember("fred16"), false);
    expect("test24", bloomFilter.isMember("fred17"), false);
    expect("test25", bloomFilter.isMember("fred18"), false);
    expect("test26", bloomFilter.isMember("fred19"), false);
}