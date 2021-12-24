#include "primes.h"

#include <cinttypes>
#include <iostream>

void primes(const int n){
    bool is_prime[n+1];
    for(std::size_t i = 0; i <= n; i++){
        is_prime[i] = true;
    }

    for(int i = 2; i <= n; i++){
        if(is_prime[i]){
            for(std::size_t j = i * i; j <= n; j += i){
                is_prime[j] = false;
            }
        }
    }

    for(std::size_t i = 2; i <= n; i++){
       if(is_prime[i]){
           std::cout << i << std::endl;
       }
    }
}
