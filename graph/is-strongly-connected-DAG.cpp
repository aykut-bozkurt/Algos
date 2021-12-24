#include "is-strongly-connected-DAG.h"

#include <cinttypes>

static Graph reverse_graph(Graph& g){
    Graph reverse_g;
    for(std::size_t i = 0; i < g.size(); i++){
        reverse_g.add_vertex(i);
    }

    for(std::size_t i = 0; i < g.size(); i++){
        for(std::size_t j = 0; j < g.size(); j++){
            if(g.has_edge(j, i)){
                reverse_g.add_edge(i, j);
            }
        }
    }

    return reverse_g;
}

static void DFS(Graph& g, bool (&visited)[5], int cur_idx){
    visited[cur_idx] = true;

    for(auto& adj_idx : g.get_adj(cur_idx)){
        if(!visited[adj_idx]){
            DFS(g, visited, adj_idx);
        }
    }
}

bool is_strongly_connected(Graph& g){
    bool visited[5] = {false};

    DFS(g, visited, 0);

    // can we reach all other vertex from 0
    for(std::size_t i = 0; i < 5; i++){
        if(!visited[i]){
            return false;
        }
    }

    // reset visited
    for(std::size_t i = 0; i < 5; i++){
        visited[i] = false;
    }
    auto reverse_g =  reverse_graph(g);
    DFS(reverse_g, visited, 0);

    // can we reach from all other vertex to 0; if so 0 already can reach to all other vertex, implies all vertex can reach all other vertex
    for(std::size_t i = 0; i < 5; i++){
        if(!visited[i]){
            return false;
        }
    }

    return true;
}
