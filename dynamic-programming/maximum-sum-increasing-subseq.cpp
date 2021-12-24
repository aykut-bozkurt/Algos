#include "maximum-sum-increasing-subseq.h"

#include <cinttypes>

int max_increasing_sum(const std::vector<int>& a){
    int sol[a.size()] = {0};
    for(std::size_t i = 0; i < a.size(); i++){
        sol[i] = a[i];
    }

    int max_increasing_sum = 0;
    for(std::size_t end_idx = 0; end_idx < a.size(); end_idx++){

        for(std::size_t start_idx = 0; start_idx < end_idx; start_idx++){
            if((a[start_idx] < a[end_idx]) && (sol[start_idx] + a[end_idx] > sol[end_idx])){
                sol[end_idx] = sol[start_idx] + a[end_idx];
            }
        }

        if(sol[end_idx] > max_increasing_sum){
            max_increasing_sum = sol[end_idx];
        }
    }

    return max_increasing_sum;
}
