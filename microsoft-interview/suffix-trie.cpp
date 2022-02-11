#include "suffix-trie.h"
#include <map>

SuffixTrie::SuffixTrie(const std::string text) {
    create_suffixes(text);
}

// O(n2)
void SuffixTrie::create_suffixes(const std::string &text) {
    std::string cur_suffix = "";
    for(int i = text.length()-1; i >= 0; i--){
        cur_suffix = text[i] + cur_suffix;
        trie.insert(cur_suffix);
    }
}

// O(n)
bool SuffixTrie::search(const std::string &pattern) {
    return trie.search(pattern);
}