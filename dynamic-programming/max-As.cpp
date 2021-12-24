#include "max-As.h"

#include <cinttypes>
#include <algorithm>

int max_As(const int N){
    int sol[N] = {0};
    for(std::size_t i = 1; i <= 6; i++){
        sol[i-1] = i;
    }

    // for each end point
    for(std::ptrdiff_t j = 7; j <= N; j++){
        // for each possible break point
        for(std::ptrdiff_t k = j - 3; k >= 1; k--){
            auto paste_count = j - k - 1;
            auto selected_text_len = sol[k-1];
            if(sol[j-1] < paste_count * selected_text_len){
                sol[j-1] = paste_count * selected_text_len;
            }
        }
    }

    return sol[N-1];
}
