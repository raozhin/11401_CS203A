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
    - 2025/11/22: Added error handling and Doxygen comments
   Developer: rao zhin <s1133305@mail.yzu.edu.tw>
 */

#include "hash_fn.h"
#include <math.h>
#include <string.h>
#include <stdio.h> //fprint
#include <stdlib.h> //NULL

/**
 * @brief Computes the hash index for an integer key.
 * @param key The integer key to hash.
 * @param m The table size.
 * @return The computed hash index (or -1 on error).
 */
int myHashInt(int key, int m) {
    unsigned long hash = 0;

    if (m <= 0) {   // m大小檢查
        fprintf(stderr, "Table size m must be positive\n");
        return -1; 
    }

    double a=sqrt(2); //multiplication method
    hash = floor(m*(fmod(key* a ,1)));
    return hash ; 
}

/**
 * @brief Computes the hash index for a string key.
 * @param str The string key to hash.
 * @param m The table size.
 * @return The computed hash index (or -1 on error).
 */
int myHashString(const char* str, int m) {
    unsigned long hash = 0;

    if (m <= 0) {   // m大小檢查
        fprintf(stderr, "Table size m must be positive\n");
        return -1; 
    }

    if (str == NULL) {// 字串指針檢查
        fprintf(stderr, "string is cannot be NULL\n");
        return -1; 
    }

    if (strlen(str) == 0) {// 空字串檢查
        fprintf(stderr, "string is empty\n");
        return 0; 
    }

    while (*str != '\0') { //polynomial rolling hash
        hash = (hash*31+ *str);
        hash %= m; 
        str++;     // 移動指針到下一個字元
    }
    return hash;
}