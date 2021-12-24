#include "non-decreasing-numbers.h"

#include <cinttypes>

int non_decreasing_numbers(const int digit){
    // [total digit][ending digit]
    int sol[digit+1][10];

    for(std::size_t i = 0; i <= digit; i++) {
        for (std::size_t j = 0; j <= 9; j++) {
            sol[i][j] = 0;
        }
    }
    sol[0][0] = 1;

    // for each digit count
    for(std::size_t i = 1; i <= digit; i++) {
        // for each ending digit
        for (std::size_t j = 0; j <= 9; j++) {
            // for each prev digit less than or equal to ending digit
            for(std::size_t k = 0; k <= j; k++){
                sol[i][j] += sol[i-1][k];
            }
        }
    }

    int sum = 0;
    for (std::size_t i = 0; i <= 9; i++) {
        sum += sol[digit][i];
    }

    return sum;
}