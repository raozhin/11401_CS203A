/*
   ========================================
   hash_fn.cpp — implement your hash functions
   ========================================

   Description:
    This file contains the hash functions for integer and string keys.

   Development History:
    - 2025/11/11: Initial implementation
    - 2025/11/17: Refactored to use hash_fn.hpp
    - 2025/11/21: Second implementation(code)

   Developer: rao zhin <s1133305@mail.yzu.edu.tw>
 */
#include "hash_fn.hpp"
#include <math.h>
int myHashInt(int key, int m) {
    unsigned long hash = 0;

    if (m <= 0) {   // m大小檢查
        cout<<"Table size m must be positive"<<endl;
        return -1; 
    }

    double a=sqrt(2); //multiplication method : use fractional part of key*a
    hash = floor(m*(fmod(key* a ,1))); 
    return hash ;  
}

int myHashString(const std::string& str, int m) {
    unsigned long hash = 0;
    if (m <= 0) {   // m大小檢查
        cout<<"Table size m must be positive"<<endl;
        return -1; 
    }

    if (str.empty()) {// 空字串檢查
        cout<<"string is empty"<<endl;
        return 0; 
    }

    for(char c :str){ //polynomial rolling hash
        hash=(hash*31+c);
        hash%=m;
    }
    return hash;
}