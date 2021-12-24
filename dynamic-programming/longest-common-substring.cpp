#include "longest-common-substring.h"

#include <cinttypes>
#include <algorithm>

int lcs(const std::string& s1, const std::string& s2){
    int sol[s1.size()][s2.size()] = {0};

    for(std::size_t i = 0; i < s1.size(); i++){
        sol[i][0] = (s1[i] == s2[0]) ? 1 : 0;
    }
    for(std::size_t i = 0; i < s2.size(); i++){
        sol[0][i] = (s2[i] == s1[0]) ? 1 : 0;
    }

    for(std::size_t i = 1; i < s1.size(); i++){
        for(std::size_t j = 1; j < s2.size(); j++){
            if(s1[i] == s2[j]){
                sol[i][j] = sol[i-1][j-1]+1;
            }
            else{
                sol[i][j] = std::max({sol[i-1][j], sol[i][j-1], sol[i-1][j-1]});
            }
        }
    }

    return sol[s1.size()-1][s2.size()-1];
}

