#pragma once

#include <string>
#include <vector>

struct Suffix{
    std::string suffix;
    int idx;

    bool operator<(const Suffix& other){
        if(suffix == other.suffix){
            return idx <= other.idx;
        }

        return suffix < other.suffix;
    }
};

class SuffixArray{
  public:
    SuffixArray(const std::string& text);

    std::vector<Suffix>& get_suffixes();

    bool search(const std::string& pattern);
  private:
    std::vector<Suffix> suffixes;

    void create_suffixes(const std::string& text);

    void create_suffixes2(const std::string& text);
};
