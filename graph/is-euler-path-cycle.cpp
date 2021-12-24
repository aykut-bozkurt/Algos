#include "is-euler-path-cycle.h"

#include <cinttypes>

static void DFS(Graph& g, bool (&visited)[5], int cur_idx){
    visited[cur_idx] = true;

    for(auto& adj_idx : g.get_adj(cur_idx)){
        if(!visited[adj_idx]){
            DFS(g, visited, adj_idx);
        }
    }
}

bool is_eulerian_path(Graph& g){
    bool visited[5] = {false};

    DFS(g, visited, 0);

    // Check if all non-zero degree vertices are visited; zero degree vertexes does not violate eularian path
    for(std::size_t i = 0; i < 5; i++){
        if(!visited[i] && g.get_adj(i).size() > 0){
            return false;
        }
    }

    // count odd degree vertexes
    int odd_degree_vertex_count = 0;
    int last_odd_degree_idx = -1;
    for(std::size_t i = 0; i < 5; i++){
        if(g.get_adj(i).size() % 2 == 1){
            odd_degree_vertex_count++;
            last_odd_degree_idx = i;
        }
    }

    if(odd_degree_vertex_count > 2){
        return false;
    }
    else{
        return true;
    }
}

bool is_eulerian_cycle(Graph& g){
    bool visited[5] = {false};

    DFS(g, visited, 0);

    // Check if all non-zero degree vertices are visited; zero degree vertexes does not violate eularian path
    for(std::size_t i = 0; i < 5; i++){
        if(!visited[i] && g.get_adj(i).size() > 0){
            return false;
        }
    }

    // count odd degree vertexes
    int odd_degree_vertex_count = 0;
    int last_odd_degree_idx = -1;
    for(std::size_t i = 0; i < 5; i++){
        if(g.get_adj(i).size() % 2 == 1){
            odd_degree_vertex_count++;
            last_odd_degree_idx = i;
        }
    }

    if(odd_degree_vertex_count == 0){
        return true;
    }
    else{
        return false;
    }
}
