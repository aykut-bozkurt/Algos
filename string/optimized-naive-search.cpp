#include "naive-search.h"

// works when all chars in pattern are different
std::vector<int> optimized_naive_search(std::string text, std::string pattern){
    std::vector<int> positions;

    for(int i = 0; i < text.length() - pattern.length() + 1; i++){
        bool found = true;
        int window_idx = i;

        for(auto& c : pattern){
            if(c != text[window_idx]){
                found = false;
                break;
            }

            window_idx++;
        }

        if(found){
            positions.push_back(i);
        }
        else{
            // we can guarantee that no match from i till window_idx because all chars in pattern are different
            i = window_idx;
        }
    }

    return positions;
}
