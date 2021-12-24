#include "stair-ways.h"

#include <cinttypes>

int stair_ways(const int N){
    int sol[N+1] = {0};
    sol[0] = 1;

    // for each stair number
    for(std::size_t i = 1; i <= N; i++){
        if(i >= 2){
            sol[i] += sol[i-2];
        }
        if(i >= 1) {
            sol[i] += sol[i-1];
        }
    }

    return sol[N];
}