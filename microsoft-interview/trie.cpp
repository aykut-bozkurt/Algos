#include "trie.h"

bool Trie::insert(const std::string& text) {
    auto cur = head;

    // find the insertion point
    int i = 0;
    while(cur->next[text[i] - 'a'] != nullptr){
        cur = cur->next[text[i] - 'a'];
        i++;

        if(i == text.length()){
            if(cur->is_word){
                // already added
                return false;
            }
            else {
                // marked as word
                cur->is_word = true;
                return true;
            }
        }
    }

    while(i < text.length()){
        TrieNode* node = new TrieNode(text[i]);

        cur->next[text[i] - 'a'] = node;
        i++;
        cur = node;

        if(i == text.length()){
            // newly added nodes
            cur->is_word = true;
            break;
        }
    }

    return true;
}

bool Trie::search(const std::string &text) {
    auto cur = head;

    int i = 0;
    while(i < text.length() && cur->next[text[i] - 'a'] != nullptr){
        cur = cur->next[text[i] - 'a'];
        i++;
    }

    if(i == text.length() && cur->is_word){
        return true;
    }
    else{
        return false;
    }
}

bool Trie::remove(const std::string &text) {
    auto cur = head;
    auto prev = cur;

    int i = 0;
    while(i < text.length() && cur->next[text[i] - 'a'] != nullptr){
        prev = cur;
        cur = cur->next[text[i] - 'a'];
        i++;
    }

    if(i == text.length() && cur->is_word){
        bool any_next = false;
        for(auto next : cur->next){
            if(next){
                any_next = true;
                break;
            }
        }

        cur->is_word = false;
        if(!any_next){
            // remove node if no children
            prev->next[text[i-1] - 'a'] = nullptr;
        }

        return true;
    }
    else{
        // not found so not removed
        return false;
    }
}
