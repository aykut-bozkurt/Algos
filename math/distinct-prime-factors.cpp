#include "distinct-prime-factors.h"

#include <cinttypes>
#include <iostream>

void distinct_prime_factors(const int n, const int m){
    int prime_factor_count[m+1] = {0};
    bool is_prime[m+1];
    for(std::size_t i = 0; i <= m; i++){
        is_prime[i] = true;
    }

    for(int i = 2; i <= m; i++){
        if(is_prime[i]){
            prime_factor_count[i] = 1;

            for(std::size_t j = i * 2; j <= m; j += i){
                is_prime[j] = false;
                prime_factor_count[j]++;
            }
        }
    }

    for(std::size_t i = n; i <= m; i++){
        std::cout << prime_factor_count[i] << std::endl;
    }
}
