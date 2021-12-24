#include "is-multiple-3.h"

#include <cmath>

bool is_multiple_of_3(int n){
    if(n < 0){
        n = -n;
    }
    else if(n == 0){
        return true;
    }
    else if(n == 1){
        return false;
    }

    int odd_set_count = 0;
    int even_set_count = 0;

    // O(logn)
    while(n){
        if(n & 1){
            odd_set_count++;
        }

        if(n & 2){
            even_set_count++;
        }

        // shift right by 2 bits after checking out rightmost 2 bits whether they are set or not
        n >>= 2;
    }

    return is_multiple_of_3(std::abs(odd_set_count - even_set_count));
}
