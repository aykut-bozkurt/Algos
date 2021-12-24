#include "is-biconnected.h"
#include "articulation-points.h"

static void DFS(Graph& g, bool (&visited)[5], int cur_idx){
    visited[cur_idx] = true;

    for(auto& adj_idx : g.get_adj(cur_idx)){
        if(!visited[adj_idx]){
            DFS(g, visited, adj_idx);
        }
    }
}

bool is_biconnected(Graph& g){
    bool visited[5] = {false};

    DFS(g, visited, 0);

    // can we reach all other vertex from 0
    for(std::size_t i = 0; i < 5; i++){
        if(!visited[i]){
            return false;
        }
    }

    // if graph is both connected and has no articulation points, then it is biconnected
    auto aps = articulation_points(g);
    return aps.size() == 0;
}
