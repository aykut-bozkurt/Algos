#include "score-ways.h"

#include <cinttypes>

int score_ways(const std::vector<int>& scores, const int score){
    int sol[score+1] = {0};
    sol[0] = 1;

    // for each step score
    for(auto& step_score : scores){
        // for each possible score
        for(std::size_t i = 1; i <= score; i++){
            if(step_score <= i){
                sol[i] += sol[i - step_score];
            }
        }
    }

    return sol[score];
}
