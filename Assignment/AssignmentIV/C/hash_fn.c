/*
   ========================================
   hash_fn.c — implement your hash functions
   ========================================

   Description:
    This file contains the hash functions for integer and string keys.

   Development History:
    - 2025/11/11: Initial implementation
    - 2025/11/17: Refactored to use hash_fn.h
    - 2025/11/21: Second implementation(code)

   Developer: rao zhin <s1133305@mail.yzu.edu.tw>
 */

#include "hash_fn.h"
#include <math.h>
#include <string.h>
int myHashInt(int key, int m) {
    unsigned long hash = 0;
    double a=sqrt(2);
    hash = floor(m*(fmod(key* a ,1)));
    return hash ; 
}

int myHashString(const char* str, int m) {
    unsigned long hash = 0;
    while (*str != '\0') {
        hash = (hash*31+ *str);
        hash %= m; 
        str++;     
    }
    return hash;
}