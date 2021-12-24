#include "cutting-rod.h"

#include <algorithm>
#include <cinttypes>

int cutting_rod(const std::vector<int>& prices){
    auto max_rod_size = prices.size();
    int sol[max_rod_size+1] = {0};

    // for each rod piece
    for(std::size_t rod_piece_idx = 0; rod_piece_idx < max_rod_size; rod_piece_idx++){
        auto rod_piece_size = rod_piece_idx + 1;
        // for each obtainable possible rod size up to max rod size
        for(std::size_t rod_size = rod_piece_size; rod_size <= max_rod_size; rod_size++){
            sol[rod_size] = std::max(sol[rod_size - rod_piece_size] + prices[rod_piece_idx], sol[rod_size]);
        }
    }

    return sol[prices.size()];
}
