#include "longest-bitonic-seq.h"

#include <cinttypes>
#include <algorithm>

int longest_bitonic_seq(const std::vector<int>& a){
    // calc lis values ending at idx
    int lis[a.size()] = {0};
    for(auto& el : lis){
        el = 1;
    }

    // for each end index
    for(std::size_t i = 1; i < a.size(); i++){
        // for each start index
        for(std::size_t j = 0; j < i; j++){
            if((a[j] < a[i]) && (lis[j] + 1 > lis[i])){
                lis[i] = lis[j] + 1;
            }
        }
    }


    // calc lds values starting at idx
    int lds[a.size()] = {0};
    for(auto& el : lds){
        el = 1;
    }

    // for each end index
    for(std::ptrdiff_t i = a.size()-2; i >= 0; i--){
        // for each start index
        for(std::ptrdiff_t j = a.size()-1; j > i; j--){
            if((a[j] < a[i]) && (lds[j] + 1 > lds[i])){
                lds[i] = lds[j] + 1;
            }
        }
    }

    // calc lbs(bitonic) values
    int max_lbs = 0;
    int lbs;
    // end index
    for(std::size_t i = 0; i < a.size(); i++){
        lbs = lis[i] + lds[i] - 1;
        if(lbs > max_lbs){
            max_lbs = lbs;
        }
    }

    return max_lbs;
}
