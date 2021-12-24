#include "min-no-change.h"

#include <cinttypes>
#include <algorithm>

int min_no_change(const std::vector<int>& changes, const int V){
    int sol[V+1] = {0};

    // for each possible sum
    for(std::size_t i = 1; i <= V; i++){
        // for each change
        for(const auto& change : changes){
            if(change <= i){
                auto sol1 = 1 + sol[i-change];
                sol[i] = (sol[i] != 0) ? std::min(sol1, sol[i]) : sol1;
            }
        }
    }

    return (sol[V]) ? sol[V] : -1;
}
