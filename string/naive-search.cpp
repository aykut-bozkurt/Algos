#include "naive-search.h"

std::vector<int> naive_search(std::string text, std::string pattern){
    std::vector<int> positions;

    for(int i = 0; i < text.length(); i++){
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
    }

    return positions;
}
