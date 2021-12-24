#include "binomial-coefficient.h"

#include <cinttypes>

int binomial_coefficient(const int n, const int k){
    int sol[n+1][n+1];
    for(std::size_t i = 0; i <= n; i++){
        for(std::size_t j = 0; j <= n; j++){
            if(j == 0 || j == i){
                sol[i][j] = 1;
            }
            else{
                sol[i][j] = 0;
            }
        }
    }

    // for each n
    for(std::size_t i = 1; i <= n; i++){
        // power up to degree
        for(std::size_t j = 1; j <= i; j++){
            // C(i,j) == C(i-1,j-1) + C(i-1.j)
            sol[i][j] = sol[i-1][j-1] + sol[i-1][j];
        }
    }

    return sol[n][k];
}
