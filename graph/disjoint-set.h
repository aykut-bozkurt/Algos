#pragma once

#include <vector>
#include <cinttypes>

class DisjointSet{
  public:
    DisjointSet(std::size_t size);

    void uunion(int v1, int v2);
    int find(int v);
  private:
    std::vector<int> parents;
};
