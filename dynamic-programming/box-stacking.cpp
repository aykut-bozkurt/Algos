#include "box-stacking.h"

#include <algorithm>
#include <cinttypes>

int box_stacking(const std::vector<std::tuple<int,int,int>>& stacks){
    std::vector<std::tuple<int,int,int>> rotated_stacks(stacks.size()*3);

    // store all base area rotations assume depth the maximum of base lines for simplicity
    std::transform(stacks.begin(), stacks.end(), rotated_stacks.begin(), [](const auto& stack) -> std::tuple<int,int,int>{
      return {std::max(std::get<0>(stack), std::get<1>(stack)), std::min(std::get<0>(stack), std::get<1>(stack)), std::get<2>(stack)};
    });
    std::transform(stacks.begin(), stacks.end(), rotated_stacks.begin() + stacks.size(), [](const auto& stack) -> std::tuple<int,int,int>{
        return {std::max(std::get<2>(stack), std::get<0>(stack)), std::min(std::get<2>(stack), std::get<0>(stack)), std::get<1>(stack)};
    });
    std::transform(stacks.begin(), stacks.end(), rotated_stacks.begin() + 2 * stacks.size(), [](const auto& stack) -> std::tuple<int,int,int>{
      return {std::max(std::get<2>(stack), std::get<1>(stack)), std::min(std::get<2>(stack), std::get<1>(stack)), std::get<0>(stack)};
    });

    // sort based on base area in decreasing order
    std::sort(rotated_stacks.begin(), rotated_stacks.end(), [](const auto& stack1, const auto& stack2){
        return (std::get<0>(stack1) * std::get<1>(stack1)) > (std::get<0>(stack2) * std::get<1>(stack2));
    });

    int sol[rotated_stacks.size()];
    for(std::size_t i = 0; i < rotated_stacks.size(); i++){
        sol[i] = std::get<2>(rotated_stacks[i]);
    }

    int max_stacks = 0;
    // for each end index
    for(std::size_t i = 1; i < rotated_stacks.size(); i++){
        // for each start index
        for(std::size_t j = 0; j < i; j++){
            if((std::get<0>(rotated_stacks[j]) > std::get<0>(rotated_stacks[i])) &&
                (std::get<1>(rotated_stacks[j]) > std::get<1>(rotated_stacks[i])) &&
                (sol[i] < (sol[j] + std::get<2>(rotated_stacks[i])))){
                sol[i] = sol[j] + std::get<2>(rotated_stacks[i]);
            }
        }

        if(sol[i] > max_stacks){
            max_stacks = sol[i];
        }
    }

    return max_stacks;
}