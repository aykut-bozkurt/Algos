#pragma once

#include <string>
#include <vector>

struct PatriciaTrieNode{
    PatriciaTrieNode(std::string val) : val(val), next(std::vector<PatriciaTrieNode*>(26)), is_word(false){}
    std::string val;
    std::vector<PatriciaTrieNode*> next;
    bool is_word;
};

class PatriciaTrie{
  public:
    PatriciaTrie(){
        head = new PatriciaTrieNode("");
    }

    bool insert(const std::string& text);

    bool search(const std::string& text);

    bool remove(const std::string& text);
  private:
    PatriciaTrieNode* head;
};