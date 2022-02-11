#include "suffix-array.h"
#include <algorithm>
#include <iostream>
#include <map>

SuffixArray::SuffixArray(const std::string& text) {
    //create_suffixes(text);
    create_suffixes2(text);
}

std::vector<Suffix>& SuffixArray::get_suffixes() {
    return suffixes;
}

// O(n2 * logn)
void SuffixArray::create_suffixes(const std::string& text) {
    for(int i = 0; i < text.length(); i++){
        this->suffixes.push_back({text.substr(i, text.length() - i), i});
    }

    std::sort(this->suffixes.begin(), this->suffixes.end());
}

// O(n * logn)
void SuffixArray::create_suffixes2(const std::string &text) {
    std::map<std::string, int> suffix_idx;

    std::string cur_suffix = "";
    for(int i = text.length()-1; i >= 0; i--){
        cur_suffix = text[i] + cur_suffix;
        suffix_idx[cur_suffix] = i;
    }

    // store suffixes in sorted order taken from map
    for(auto& [suffix, idx] : suffix_idx){
        this->suffixes.push_back(Suffix{suffix, idx});
    }
}

// O(n * logn)
bool SuffixArray::search(const std::string& pattern) {
    int low = 0;
    int high = suffixes.size()-1;
    int mid;

    while(low <= high){
        mid = low + (high - low) / 2;

        if(suffixes[mid].suffix.rfind(pattern) == 0){
            std::cout << "Found at: " << suffixes[mid].idx << std::endl;
            return true;
        }
        else if(suffixes[mid].suffix > pattern){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }

    return false;
}
