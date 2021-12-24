#include "n-digit-number-of-sum.h"

#include <cinttypes>

int n_digit_number_of_sum(const int digit, const int sum){
    // [total digit][possible sum]
    int sol[digit+1][sum+1];

    for(std::size_t i = 0; i <= digit; i++) {
        for (std::size_t j = 0; j <= sum; j++) {
            sol[i][j] = 0;
        }
    }
    sol[0][0] = 1;

    // for each digit count
    for(std::size_t i = 1; i <= digit; i++) {
        // for each possible sum
        for (std::size_t j = 1; j <= sum; j++) {
            // for each possible digit
            for(std::size_t k = 0; k <= 9; k++){
                if(k <= j){
                    sol[i][j] += sol[i-1][j-k];
                }
            }
        }
    }

    return sol[digit][sum];
}
