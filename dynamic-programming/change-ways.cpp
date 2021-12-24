#include "change-ways.h"

#include <cinttypes>

int change_ways(const std::vector<int>& changes, const int N){
    int sol[N+1] = {0};
    sol[0] = 1;

    // for each change
    for(auto& change : changes){
        // for each money up to N
        for(std::size_t money = change; money <= N; money++){
            sol[money] += sol[money - change];
        }
    }

    return sol[N];
}
