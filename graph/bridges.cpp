#include "bridges.h"

#include <iostream>

static constexpr int N = 5;

static void bridges(Graph& g, int cur_idx, int parent_idx, bool (&visited)[N], int& cur_time, int (&disc)[N], int (&low)[N]){
    visited[cur_idx] = true;

    disc[cur_idx] = cur_time;
    low[cur_idx] = disc[cur_idx];
    cur_time++;

    for(auto& adj_idx : g.get_adj(cur_idx)){
        if(!visited[adj_idx]){
            bridges(g, adj_idx, cur_idx, visited, cur_time, disc, low);

            low[cur_idx] = std::min(low[cur_idx], low[adj_idx]);

            // if we cannot access cur_idx or earliest vertexes if we cut the edge, then the edge is a bridge
            if(low[adj_idx] > disc[cur_idx]){
                std::cout << cur_idx << " - " << adj_idx << std::endl;
            }
        }
        else{
            if(adj_idx != parent_idx){
                low[cur_idx] = std::min(low[cur_idx], disc[adj_idx]);
            }
        }
    }
}

void bridges(Graph& g){
    bool visited[N] = {false};
    int disc[N] = {0}; // discovery time of a vertex
    int low[N] = {0}; // lowest discovery time of a vertex from subtree rooted with vertex
    int cur_time = 0; // global discovery time

    bridges(g, 0, -1, visited, cur_time, disc, low);
}
