#pragma once

#include <list>
#include <vector>

struct Edge{
    int src;
    int dst;
    int weight;

    friend bool operator> (const Edge& e1,const Edge& e2){
        return e1.weight > e2.weight;
    }
    friend bool operator< (const Edge& e1,const Edge& e2){
        return e1.weight < e2.weight;
    }
};

class GraphWithEdge{
  public:
    std::list<Edge>& get_adj(int v);
    void add_vertex(int v);
    void remove_vertex(int v);
    bool has_vertex(int v);

    void add_edge(int v1, int v2, int weight);
    void add_undirected_edge(int v1, int v2, int weight);
    void remove_edge(int v1, int v2);
    bool has_edge(int v1, int v2);
    int get_edge_len(int v1, int v2);

    std::size_t size();
  private:
    std::vector<std::list<Edge>> adj;
};
