#include <stdlib.h>

#ifndef __HASH_H__
#define __HASH_H__

unsigned hash(const char *s);

struct hash_table{
    unsigned int buckets_cnt; /*count of number of buckets. Usually a prime number */
    void* arr; /* internal array of pointers */
};

#endif