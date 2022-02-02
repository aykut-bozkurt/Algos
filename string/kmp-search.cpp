#include "naive-search.h"

static std::vector<int> lps_table(const std::string& pattern){
    // stores backtrack idx on a mismatch on next pattern idx (we do not go to beginning, instead we go to backtrack idx)
    std::vector<int> lps(pattern.length());
    lps[0] = 0; // means that when mismatch on next pattern_idx(=1 for pattern_idx=0), then backtrack to pattern_idx=0

    int prefix_idx = 0; // matched prefix idx (end point idx for prefix)
    int pattern_idx = 1; // pattern idx starts at 1 (stores backtrack idx for a mismatch on pattern_idx=2)

    while(pattern_idx < pattern.length()){
        // we have char match
        if(pattern[pattern_idx] == pattern[prefix_idx]){
            // so extend the prefix_idx
            prefix_idx++;

            // backtrack idx is the prefix_idx for pattern_idx
            lps[pattern_idx] = prefix_idx;

            // advance pattern idx
            pattern_idx++;
        }
        // no char match
        else{
            // we have prefix_idx of 0
            if(prefix_idx == 0){
                // backtrack idx is 0
                lps[pattern_idx] = 0;

                // advance pattern idx
                pattern_idx++;
            }
            // we have prefix_idx of > 0
            else{
                // set matched prefix_idx to backtrack idx for prefix_idx-1,
                // because we know that we matched until backtrack idx for prefix_idx-1
                prefix_idx = lps[prefix_idx-1];
            }
        }
    }

    return lps;
}

std::vector<int> kmp_search(std::string text, std::string pattern){
    std::vector<int> positions;

    std::vector<int> lps = lps_table(pattern);

    int i = 0; // text idx
    int j = 0; // pattern idx
    while(i < text.length()){
        // we have char match
        if(text[i] == pattern[j]){
            // advance text idx
            i++;

            // advance pattern idx
            j++;

            // if matched pattern len is equal to pattern len, then there is a match
            if(j == pattern.length()){
                // add match point in text
                positions.push_back(i-j);

                // set pattern idx to backtrack point for pattern-1,
                // because we know that pattern-1 is matched so far, and we can search from backtrack idx for it instead of beginning
                j = lps[j-1];
            }
        }
        // no char match
        else{
            // matched pattern len is 0 so far
            if(j == 0){
                // advance text idx
                i++;
            }
            // matched pattern len is > 0 so far
            else{
                // move pattern idx to backtrack idx for pattern-1,
                // because we know that pattern-1 is matched so far, and we can search from backtrack idx for it instead of beginning
                j = lps[j-1];
            }
        }
    }

    return positions;
}
