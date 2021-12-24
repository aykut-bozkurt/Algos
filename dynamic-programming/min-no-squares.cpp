#include "min-no-squares.h"

#include <cinttypes>
#include <algorithm>

int min_no_squares(const int n){
    int sol[n+1] = {0};

    // for each possible n
    for(std::size_t i = 1; i <= n; i++){
        // for each possible square root of n
        for(std::size_t x = 1; x*x <= n; x++){
            if(x*x <= i){
                auto sol1 = sol[i-x*x] + 1;
                sol[i] = (sol[i] != 0) ? std::min(sol1, sol[i]) : sol1;
            }
        }
    }

    return sol[n];
}
