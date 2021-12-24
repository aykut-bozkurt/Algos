#include "tiling.h"

#include <cinttypes>

int tiling(const int N){
    int sol[N+1];
    sol[0] = 0;
    sol[1] = 1;

    for(std::size_t i = 2; i <= N; i++){
        sol[i] = sol[i-2] + sol[i-1];
    }

    return sol[N];
}
