#pragma once

#include <list>
#include <vector>

class Graph{
  public:
    std::list<int>& get_adj(int v);
    void add_vertex(int v);
    void remove_vertex(int v);
    bool has_vertex(int v);

    void add_edge(int v1, int v2);
    void add_undirected_edge(int v1, int v2);

    void remove_edge(int v1, int v2);
    bool has_edge(int v1, int v2);

    std::size_t size();
  private:
    std::vector<std::list<int>> adj;
};
