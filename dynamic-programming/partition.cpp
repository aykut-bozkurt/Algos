#include "partition.h"

#include <numeric>
#include <cinttypes>

bool partition(const std::vector<int>& a){
    auto sum = std::reduce(a.begin(), a.end(), 0);
    if(sum % 2 == 1){
        return false;
    }

    // [possible sum][end index]
    bool sol[sum/2 + 1][a.size()];
    for(std::size_t i = 0; i <= sum/2; i++){
        sol[0][i] = true;
    }
    for(std::size_t i = 0; i < a.size(); i++){
        sol[i][0] = (a[0] == i);
    }

    // for each possible sum
    for(std::size_t i = 1; i <= sum/2; i++){
        // for each end index
        for(std::size_t j = 1; j < a.size(); j++){
            // set current step true if prev step has same sum, else set it false
            sol[i][j] = sol[i][j-1];
            if(i >= a[j]){
                // consider not including cur element in sum
                sol[i][j] = sol[i][j] || sol[i-a[j]][j-1];
            }
        }
    }

    return sol[a.size()][sum/2];
}