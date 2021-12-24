#include "subset-sum.h"

#include <cinttypes>
#include <numeric>

bool subset_sum(const std::vector<int>& a, const int sum){
    bool sol[a.size()+1][sum+1];
    for(std::size_t i = 0; i <= sum; i++){
        // if sum is zero, set solution true; else false
        sol[i][0] = true;
    }

    for(std::size_t i = 1; i <= a.size(); i++){
        // if set is empty set solution false
        sol[0][i] = false;
    }

    // for each elem
    for(std::size_t i = 1; i <= a.size(); i++){
        // for each possible sum
        for(std::size_t j = 1; j <= sum; j++){
            if(a[i-1] <= j){
                // if prev element is less than or equal to current sum, check bot used and unused cases of prev element
                sol[i][j] = sol[i-1][j] || sol[i-1][j-a[i-1]];
            }
            else{
                // if prev element is greater than current sum, do not use prev element
                sol[i][j] = sol[i-1][j];
            }
        }
    }

    return sol[a.size()][sum];
}
