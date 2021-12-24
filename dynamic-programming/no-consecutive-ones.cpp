#include "no-consecutive-ones.h"

#include <cinttypes>

int no_consecutive_ones(const int N){
    int sol_ending_one[N+1] = {0};
    int sol_ending_zero[N+1] = {0};

    sol_ending_one[1] = 1;
    sol_ending_zero[1] = 1;

    for(std::size_t i = 2; i <= N; i++){
        sol_ending_one[i] = sol_ending_zero[i-1];
        sol_ending_zero[i] = sol_ending_one[i-1] + sol_ending_zero[i-1];
    }

    return sol_ending_one[N] + sol_ending_zero[N];
}
