#include "fibonacci.h"

#include <cinttypes>

int fibonacci(const int n){
    int sol[n+1];
    sol[0] = 1;
    sol[1] = 1;

    for(std::size_t i = 2; i <= n; i++){
        sol[i] = sol[i-1] + sol[i-2];
    }

    return sol[n];
}
