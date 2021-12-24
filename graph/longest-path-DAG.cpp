#include "longest-path-DAG.h"
#include "graph-with-edge.h"

#include <stack>
#include <iostream>

static void topo_sort(GraphWithEdge& g, int current_idx, bool (&visited)[6], std::stack<int>& topo){
    if(!visited[current_idx]){
        visited[current_idx] = true;

        for(auto& edge : g.get_adj(current_idx)){
            if(!visited[edge.dst]){
                topo_sort(g, edge.dst, visited, topo);
            }
        }

        // if there is no depth to go down, this is leaf, add it to topo
        topo.push(current_idx);
    }
}

void longest_path_DAG(GraphWithEdge& g, int src){
    bool visited[6] = {false};
    std::stack<int> topo;

    // topo sort vertices
    for(std::size_t idx = 0; idx < g.size(); idx++){
        if(!visited[idx]){
            topo_sort(g, idx, visited, topo);
        }
    }

    int distance[6];
    for(std::size_t i = 0; i < 6; i++){
        distance[i] = INT32_MIN;
    }
    distance[src] = 0;

    // calculate the longest distances btw src and other vertices
    while(!topo.empty()){
        auto& vertex_idx = topo.top();
        topo.pop();

        if(distance[vertex_idx] != INT32_MIN){
            for(auto& edge : g.get_adj(vertex_idx)){
                if(distance[vertex_idx] + edge.weight > distance[edge.dst]){
                    distance[edge.dst] = distance[vertex_idx] + edge.weight;
                }
            }
        }
    }

    // print the longest distances btw src and other vertices
    for(std::size_t i = 0; i < 6; i++){
        std::cout << "Longest_Dist(" << src << " - " << i << ") = " << (distance[i] == INT32_MIN ? "-INF" : std::to_string(distance[i])) << std::endl;
    }
}

