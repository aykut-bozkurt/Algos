#include "topological-sort.h"

#include <stack>
#include <iostream>

static void print_topo(std::stack<int>& topo){
    while(!topo.empty()){
        std::cout << topo.top();
        topo.pop();
        if(!topo.empty()){
            std::cout << " -> ";
        }
    }
    std::cout << std::endl;
}

static void topo_sort(Graph& g, int current_idx, bool (&visited)[6], std::stack<int>& topo){
    if(!visited[current_idx]){
        visited[current_idx] = true;

        for(auto& adj_idx : g.get_adj(current_idx)){
            if(!visited[adj_idx]){
                topo_sort(g, adj_idx, visited, topo);
            }
        }

        // if there is no depth to go down, this is leaf, add it to topo
        topo.push(current_idx);
    }
}

void topological_sort(Graph& g){
    bool visited[6] = {false};
    std::stack<int> topo;

    for(std::size_t idx = 0; idx < g.size(); idx++){
        if(!visited[idx]){
            topo_sort(g, idx, visited, topo);
        }
    }

    print_topo(topo);
}
