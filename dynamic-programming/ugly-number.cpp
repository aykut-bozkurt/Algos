#include "ugly-number.h"

#include <algorithm>
#include <cinttypes>

int ugly_number(const int n){
    int sol[n];
    sol[0] = 1;

    auto next_ugly_2 = 2;
    auto next_ugly_2_idx = 1;

    auto next_ugly_3 = 3;
    auto next_ugly_3_idx = 1;

    auto next_ugly_5 = 5;
    auto next_ugly_5_idx = 1;

    for(std::size_t i = 1; i <  n; i++){
        sol[i] = std::min({next_ugly_2, next_ugly_3, next_ugly_5});

        if(sol[i] == next_ugly_2){
            // remember the next multiple of 2
            next_ugly_2 = 2 * sol[next_ugly_2_idx];
            // if it is multiple of 2 increment idx
            next_ugly_2_idx++;
        }
        if(sol[i] == next_ugly_3){
            // remember the next multiple of 3
            next_ugly_3 = 3 * sol[next_ugly_3_idx];
            // if it is multiple of 3 increment idx
            next_ugly_3_idx++;
        }
        if(sol[i] == next_ugly_5){
            // remember the next multiple of 5
            next_ugly_5 = 5 * sol[next_ugly_5_idx];
            // if it is multiple of 5 increment idx
            next_ugly_5_idx++;
        }
    }

    return sol[n-1];
}
