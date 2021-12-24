#include "ways-for-building.h"

#include <cinttypes>

int ways_for_building(const int n){
    int sol_ending_building[n+1] = {0};
    int sol_ending_space[n+1] = {0};

    sol_ending_building[1] = 1;
    sol_ending_space[1] = 1;

    for(std::size_t i = 2; i <= n; i++){
        sol_ending_building[i] = sol_ending_space[i-1];
        sol_ending_space[i] = sol_ending_building[i-1] + sol_ending_space[i-1];
    }

    return (sol_ending_building[n] + sol_ending_space[n]) * (sol_ending_building[n] + sol_ending_space[n]);
}
