#include "min-jump.h"

#include <cinttypes>

int min_jumps(const std::vector<int>& jumps){
    int sol[jumps.size()];
    for(std::size_t i = 0; i < jumps.size(); i++){
        sol[i] = 0;
    }

    // for each start index
    for(std::size_t i = 0; i < jumps.size(); i++){
        if(jumps[i] != 0){
            // for each possible jump from startindex
            for(std::size_t j = i+1; j <= (i + jumps[i]); j++){
                if(j < jumps.size() && (sol[j] == 0 || (sol[j] > (sol[i] + 1)))){
                    sol[j] = sol[i] + 1;
                }
            }
        }
    }

    return (sol[jumps.size()-1] == 0) ? -1 : sol[jumps.size()-1];
}
