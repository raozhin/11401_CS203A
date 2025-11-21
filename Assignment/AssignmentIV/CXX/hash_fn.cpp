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
    double a=sqrt(2); //multiplication method
    hash = floor(m*(fmod(key* a ,1))); 
    return hash ;  
}

int myHashString(const std::string& str, int m) {
    unsigned long hash = 0;
    
    for(char c :str){ //polynomial rolling hash
        hash=(hash*31+c);
        hash%=m;
    }
    return hash;
}