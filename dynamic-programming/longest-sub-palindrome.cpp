#include "longest-sub-palindrome.h"

#include <cinttypes>

int longest_sub_palindrome(const std::string& s){
    int sol[s.size()][s.size()];
    for(std::size_t i = 0; i < s.size(); i++){
        for(std::size_t j = 0; j < s.size(); j++){
            // length of 1 palindromes
            sol[i][j] = (i == j) ? 1 : 0;
        }
    }

    // for each palindrome length
    for(std::size_t len = 2; len <= s.size(); len++){
        // for each start idx
        for(std::size_t j = 0; j <= s.size()-len; j++){
            auto start_idx = j;
            auto end_idx = start_idx+len-1;
            if(s[start_idx] == s[end_idx]){
                sol[start_idx][end_idx] = sol[start_idx+1][end_idx-1] + 2;
            }
            else{
                sol[start_idx][end_idx] = std::max(sol[start_idx+1][end_idx], sol[start_idx][end_idx-1]);
            }
        }
    }

    return sol[0][s.size()-1];
}