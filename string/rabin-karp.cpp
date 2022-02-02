#include "naive-search.h"

std::vector<int> rk_search(std::string text, std::string pattern){
    std::vector<int> positions;

    int total_windows = text.length() - pattern.length() + 1;
    int text_window_hashes[total_windows] = {0};
    int first_window_text_hash = 0;
    int pattern_hash = 0;

    int d = 1;
    for(int i = pattern.length()-1; i >= 0; i--){
        pattern_hash = pattern_hash + d * (int)pattern[i];
        first_window_text_hash = first_window_text_hash + d * (int)text[i];

        d *= 256;
    }
    int highest_digit = d;
    if(pattern_hash == first_window_text_hash){
        positions.push_back(0);
    }

    int cur_window_text_hash = first_window_text_hash;
    for(int i = 1; i < total_windows; i++){
        // using prev hash val; remove prev digit, and add next digit to calculate next hash val
        cur_window_text_hash = 256 * (cur_window_text_hash - (int)text[i] * highest_digit) + (int)text[i+pattern.length()-1];

        if(cur_window_text_hash == pattern_hash){
            // check match is true only when hashes match

            bool match = true;

            int pattern_idx = 0;
            for(int j = i; j < i + pattern.length(); j++){
                if(text[j] != pattern[pattern_idx]){
                    match = false;
                    break;
                }

                pattern_idx++;
            }

            if(match){
                positions.push_back(i);
            }
        }
    }

    return positions;
}
