#include "permutations-of-string.h"

#include <cinttypes>
#include <iostream>

void permutation_of_string(std::string& s, int start_idx, int end_idx){
    if(start_idx == end_idx){
        std::cout << s << std::endl;
    }
    else{
        for(std::size_t i = start_idx; i <= end_idx; i++){
            std::swap(s[start_idx], s[i]);

            permutation_of_string(s, start_idx+1, end_idx);

            std::swap(s[i], s[start_idx]);
        }
    }
}
