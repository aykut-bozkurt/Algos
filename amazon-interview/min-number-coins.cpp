#include "min-number-coins.h"

#include <algorithm>

int min_coins(const std::vector<int>& coins, const int sum){
    int sol[sum+1] = {0};
    for(int cur_sum = 1; cur_sum <= sum; cur_sum++){
        sol[cur_sum] = INT32_MAX;
    }

    for(auto& coin : coins){
        for(int cur_sum = 1; cur_sum <= sum; cur_sum++){
            if(cur_sum >= coin){
                sol[cur_sum] = (sol[cur_sum] == 0) ? sol[cur_sum - coin] + 1 : std::min(sol[cur_sum], sol[cur_sum - coin] + 1);
            }
        }
    }

    return sol[sum];
}
