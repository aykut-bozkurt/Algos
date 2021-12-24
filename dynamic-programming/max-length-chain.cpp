#include "max-length-chain.h"

#include <cinttypes>

int max_chain_pairs(const std::vector<std::pair<int,int>>& pairs){
    int sol[pairs.size()];
    for(std::size_t i = 0; i < pairs.size(); i++){
        sol[i] = 1;
    }

    int max_chain = 0;
    // for each end index
    for(std::size_t i = 1; i < pairs.size(); i++){
        // for each start index
        for(std::size_t j = 0; j < i; j++){
            if((pairs[j].second < pairs[i].first) && (sol[i] < sol[j] + 1)){
                sol[i] = sol[j] + 1;
            }
        }

        if(sol[i] > max_chain){
            max_chain = sol[i];
        }
    }

    return max_chain;
}