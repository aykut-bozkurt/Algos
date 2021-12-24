#include "longest-increasing-subseq.h"

#include <cinttypes>

int lis(const std::vector<int>& a){
    int sol[a.size()] = {0};
    for(auto& el : sol){
        el = 1;
    }
    int max_increasing_count = 1;

    // end index
    for(std::size_t i = 1; i < a.size(); i++){
        int cur_max = 0;

        // start index
        for(std::size_t j = 0; j < i; j++){
            if((a[j] < a[i]) && (sol[j] + 1 > sol[i])){
                sol[i] = sol[j] + 1;
            }
        }

        if(sol[i] > max_increasing_count){
            max_increasing_count = sol[i];
        }
    }

    return max_increasing_count;
}
