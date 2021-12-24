#include "subset-sum.h"

#include <cinttypes>
#include <iostream>

static void print_subset(const int (&sol)[8]){
    for(std::size_t i = 0; i < 8; i++){
        std::cout << sol[i] << " ";
    }
    std::cout << std::endl;
}

static inline bool is_safe_subset(const int (&sol)[8], const int (&a)[8], const int added_idx, const int cur_sum, const int K){
    return (sol[added_idx] == 0) && (cur_sum + a[added_idx] <= K);
}

void subset_sum(const int (&a)[8], int (&sol)[8], int cur_idx, int cur_sum, const int K){
    if(cur_sum == K){
        print_subset(sol);
        return;
    }

    for(std::size_t i = cur_idx; i < 8; i++){
        if(is_safe_subset(sol, a, i, cur_sum, K)){
            cur_idx++;
            cur_sum += a[i];
            sol[i] = 1;

            subset_sum(a, sol, cur_idx, cur_sum, K);

            cur_idx--;
            cur_sum -= a[i];
            sol[i] = 0;
        }
    }
}
