#pragma once

#include <vector>
#include <string>

struct TrieNode{
    TrieNode(char val) : val(val), next(std::vector<TrieNode*>(26)), is_word(false){}
    char val;
    std::vector<TrieNode*> next;
    bool is_word;
};

class Trie{
  public:
    Trie(){
        head = new TrieNode(' ');
    };

    bool insert(const std::string& text);

    bool search(const std::string& text);

    bool remove(const std::string& text);
  private:
    TrieNode* head;
};