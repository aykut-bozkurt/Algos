#pragma once

#include <string>

#include "patricia-trie.h"

struct SuffixTrie{
  public:
    SuffixTrie(const std::string text);

    bool search(const std::string& pattern);
  private:
    PatriciaTrie trie;

    void create_suffixes(const std::string& text);
};