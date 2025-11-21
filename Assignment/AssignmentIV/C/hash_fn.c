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
#include <stdio.h>
#include <stdlib.h>
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

int myHashString(const char* str, int m) {
    unsigned long hash = 0;

    if (m <= 0) {   // m大小檢查
        cout<<"table size m must be positive."<<endl;
        return -1; 
    }

    if (str == NULL) {// 字串指針檢查
        cout<<"string is cannot be NULL"<<endl;
        return -1; 
    }

    if (strlen(str) == 0) {// 空字串檢查
        cout<<"string is empty"<<endl;
        return -1; 
    }

    while (*str != '\0') { //polynomial rolling hash
        hash = (hash*31+ *str);
        hash %= m; 
        str++;     // 移動指針到下一個字元
    }
    return hash;
}