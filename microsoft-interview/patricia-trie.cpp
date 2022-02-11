#include "patricia-trie.h"

bool PatriciaTrie::insert(const std::string& text) {
    auto cur = head;

    // find insertion point
    int j = 0; // store text idx
    while(cur->next[text[j] - 'a'] != nullptr){
        int init_j = j;
        cur = cur->next[text[j] - 'a'];

        int k = 0; // store cur node's string value idx
        for(; j < text.length(); j++){
            if(text[j] != cur->val[k]){
                break;
            }
            k++;
        }

        if(k == cur->val.length()){
            if(j == text.length()){
                if(cur->is_word){
                    // already inserted
                    return false;
                }
                else{
                    // mark as inserted
                    cur->is_word = true;
                    return true;
                }
            }
        }
        else{
            if((j-init_j) < cur->val.length()){
                // uncommon node part
                PatriciaTrieNode* dividedNode = new PatriciaTrieNode(cur->val.substr(j-init_j));
                dividedNode->next = cur->next;
                dividedNode->is_word = cur->is_word;

                // common part
                cur->val = cur->val.substr(0, j-init_j);
                cur->next = std::vector<PatriciaTrieNode*>(26, nullptr);
                cur->next[dividedNode->val[0] - 'a'] = dividedNode;

                if(j != text.length()){
                    // uncommon text part
                    PatriciaTrieNode* dividedText = new PatriciaTrieNode(text.substr(j));
                    dividedText->is_word = true;
                    cur->next[text[j] - 'a'] = dividedText;
                }
                else{
                    cur->is_word = true;
                }

                return true;
            }
            else{
                // add uncommon text part as new node
                PatriciaTrieNode* node = new PatriciaTrieNode(text.substr(j));
                node->is_word = true;
                cur->next[text[j] - 'a'] = node;

                return true;
            }
        }
    }

    PatriciaTrieNode* node = new PatriciaTrieNode(text.substr(j));
    node->is_word = true;
    cur->next[text[j] - 'a'] = node;

    return true;
}

bool PatriciaTrie::remove(const std::string& text) {
    auto cur = head;
    auto prev = cur;

    int j = 0; // store text idx
    while(cur->next[text[j] - 'a'] != nullptr){
        int init_j = j;
        prev = cur;
        cur = cur->next[text[j] - 'a'];

        int k = 0; // store cur node's string value idx
        for(; j < text.length(); j++){
            if(text[j] != cur->val[k]){
                break;
            }
            k++;
        }

        if(j == text.length() && k == cur->val.length() && cur->is_word) {
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
                prev->next[text[init_j] - 'a'] = nullptr;
            }

            return true;
        }
    }

    return false;
}

bool PatriciaTrie::search(const std::string& text) {
    auto cur = head;

    int j = 0; // store text idx
    while(cur->next[text[j] - 'a'] != nullptr){
        cur = cur->next[text[j] - 'a'];

        int k = 0; // store cur node's string value idx
        for(; j < text.length(); j++){
            if(text[j] != cur->val[k]){
                break;
            }
            k++;
        }

        if(j == text.length() && k == cur->val.length() && cur->is_word) {
            return true;
        }
    }

    return false;
}