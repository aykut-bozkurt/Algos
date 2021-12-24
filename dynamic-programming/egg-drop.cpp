#include "egg-drop.h"

#include <cinttypes>
#include <algorithm>

int egg_drop(const int n, const int k){
    int sol[n+1][k+1];
    for(std::size_t egg = 0; egg <= n; egg++){
        for(std::size_t floor = 0; floor <= k; floor++){
            if(egg == 1){
                sol[egg][floor] = floor;
            }
            else if(floor == 1){
                sol[egg][floor] = 1;
            }
            else{
                sol[egg][floor] = 0;
            }
        }
    }

    int res;
    // for each egg
    for(std::size_t egg = 2; egg <= n; egg++){
        // for each floor
        for(std::size_t floor = 2; floor <= k; floor++){
            sol[egg][floor] = INT32_MAX;
            // for each try_floor in total floor
            for(std::size_t try_floor = 1; try_floor <= floor; try_floor++){
                // egg is broken
                auto sol1 = sol[egg-1][try_floor-1];
                // egg is survived
                auto sol2 = sol[egg][floor-try_floor];

                res = std::max(sol1, sol2) + 1;
                if(res < sol[egg][floor]){
                    sol[egg][floor] = res;
                }
            }
        }
    }

    return sol[n][k];
}