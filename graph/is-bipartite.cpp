#include "is-bipartite.h"

#include <cinttypes>

static bool is_bipartite(Graph& g, bool (&visited)[4], int cur_idx, int cur_color, int (&colors)[4]){
    visited[cur_idx] = true;
    colors[cur_idx] = cur_color;

    for(auto& adj_idx : g.get_adj(cur_idx)){
        if(!visited[adj_idx] && !is_bipartite(g, visited, adj_idx, (cur_color == 1) ? 2 : 1, colors)){
            return false;
        }
        else if(colors[adj_idx] != 0 && colors[adj_idx] == cur_color){
            return false;
        }
    }

    return true;
}

bool is_bipartite(Graph& g){
    bool visited[4] = {false};
    int colors[4] = {0};

    // call for each unvisited vertex, because graph can contain unconnected components
    for(std::size_t idx = 0; idx < 4; idx++){
        if(!visited[idx]){
            if(!is_bipartite(g, visited, idx, 1, colors)){
                return false;
            }
        }
    }

    return true;
}
