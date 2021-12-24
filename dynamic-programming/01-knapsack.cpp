#include "01-knapsack.h"

#include <cinttypes>
#include <algorithm>

int knapsack_01(const std::vector<int>& weights, const std::vector<int>& values, const int W){
    int sol[weights.size()+1][W+1];
    for(std::size_t i = 0; i <= weights.size(); i++){
        // if knapsack capacity is 0, 0 val is obtained
        sol[i][0] = 0;
    }
    for(std::size_t i = 0; i <= W; i++){
        // if no item is considered to be put into knapsack, 0 val is obtained
        sol[0][i] = 0;
    }

    // for each item
    for(std::size_t i = 1; i <= weights.size(); i++){
        // for each possible knapsack capacity
        for(std::size_t cur_weight = 1; cur_weight <= W; cur_weight++){
            if(weights[i-1] <= cur_weight){
                // using cur item
                auto sol1 = sol[i-1][cur_weight - weights[i-1]] + values[i-1];
                // not using cur item
                auto sol2 = sol[i-1][cur_weight];

                sol[i][cur_weight] = std::max(sol1, sol2);
            }
            else{
                // not using cur item
                sol[i][cur_weight] = sol[i-1][cur_weight];
            }
        }
    }

    return sol[weights.size()][W];
}
