#include "is-tree.h"

#include <cinttypes>

static bool has_cycle(Graph& g, int cur_vertex, int parent_vertex, bool (&visited)[5]){
    if(!visited[cur_vertex]){
        visited[cur_vertex] = true;

        for(auto& adj_idx : g.get_adj(cur_vertex)){
            // if adjacent is not visited yet
            if(!visited[adj_idx]){
                // recurse in depth
                if(has_cycle(g, adj_idx, cur_vertex, visited)){
                    return true;
                }
            }
            // else if adjacent is previsited and it is not parent
            else if(adj_idx != parent_vertex){
                return true;
            }
        }
    }

    return false;
}

bool is_tree(Graph& g){
    bool visited[5] = {false};

    // should not contain cycle
    if(has_cycle(g, 0, -1, visited)){
        return false;
    }

    // should be strongly connected from all nodes
    for(std::size_t i = 0; i < 5; i++){
        if(!visited[i]){
            return false;
        }
    }

    return true;
}
