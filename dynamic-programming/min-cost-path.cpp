#include "min-cost-path.h"

#include <cinttypes>
#include <algorithm>

int min_cost_path(int cost[3][3], const int m, const int n){
    int sol[3][3];
    for(std::size_t i = 0; i < 3; i++){
        for(std::size_t j = 0; j < 3; j++){
            sol[i][j] = 0;
        }
    }

    for(std::size_t i = 0; i < 3; i++){
        for(std::size_t j = 0; j < 3; j++){
            if(i > 0 && j > 0){
                sol[i][j] = cost[i][j] + std::min({sol[i-1][j-1], sol[i-1][j], sol[i][j-1]});
            }
            else if(i > 0){
                sol[i][j] = cost[i][j] + sol[i-1][j];
            }
            else if(j > 0){
                sol[i][j] = cost[i][j] + sol[i][j-1];
            }
            else{
                sol[i][j] = cost[0][0];
            }
        }
    }

    return sol[m][n];
}
