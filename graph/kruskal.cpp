#include "kruskal.h"
#include "disjoint-set.h"

#include <queue>
#include <iostream>

static void print_MST(std::queue<Edge>& mst){
    while(!mst.empty()){
        auto& edge = mst.front();
        std::cout << edge.src << " - " << edge.dst << std::endl;
        mst.pop();
    }
}

void kruskal(GraphWithEdge& g){
    DisjointSet edge_set(g.size());
    std::queue<Edge> mst;
    std::priority_queue<Edge, std::vector<Edge>, std::greater<Edge>> edges;
    for(std::size_t i = 0; i < g.size(); i++){
        for(auto& edge : g.get_adj(i)){
            edges.push(edge);
        }
    }

    while(!edges.empty()){
        auto edge = edges.top();
        edges.pop();

        int parent1 = edge_set.find(edge.src);
        int parent2 = edge_set.find(edge.dst);

        // cycle check
        if(parent1 != parent2){
            mst.push(edge);
            edge_set.uunion(parent1, parent2);
        }
    }

    if(mst.size() == g.size() - 1){
        print_MST(mst);
    }
    else{
        std::cout << "No MST found!" << std::endl;
    }
}
