#include "articulation-points.h"

#include <cinttypes>

static constexpr int N = 7;

static void articulation_points(Graph& g, int cur_idx, int parent_idx, bool (&visited)[N], bool (&is_ap)[N], int& cur_time, int (&disc)[N], int (&low)[N]){
    visited[cur_idx] = true;

    disc[cur_idx] = cur_time;
    low[cur_idx] = disc[cur_idx];
    cur_time++;

    int children = 0;

    for(auto& adj_idx : g.get_adj(cur_idx)){
        if(!visited[adj_idx]){
            children++;

            articulation_points(g, adj_idx, cur_idx, visited, is_ap, cur_time, disc, low);

            // after traversing adjacent, if adj has a back edge to a vertex with lower discovery time than low of current vertex, then update low of current vertex
            low[cur_idx] = std::min(low[cur_idx], low[adj_idx]);

            // after traversing adjacent, check if it has a back edge to a vertex with lower discovery time than current vertex
            if(parent_idx != -1 && low[adj_idx] >= disc[cur_idx]){
                is_ap[cur_idx] = true;
            }
        }
        else{
            if(adj_idx != parent_idx){
                low[cur_idx] = std::min(low[cur_idx], disc[adj_idx]);
            }
        }
    }

    // if vetex is root and has at least 2 children, then it is an articulation point
    if(parent_idx == -1 && children > 1){
        is_ap[cur_idx] = true;
    }
}

std::vector<int> articulation_points(Graph& g){
    bool visited[N] = {false};
    bool is_ap[N] = {false}; // if it is articulation point
    int disc[N] = {0}; // discovery time of a vertex
    int low[N] = {0}; // lowest discovery time of a vertex from subtree rooted with vertex
    int cur_time = 0; // global discovery time

    articulation_points(g, 0, -1, visited, is_ap, cur_time, disc, low);

    std::vector<int> articulation_points;
    for(std::size_t i = 0; i < N; i++){
        if(is_ap[i]){
            articulation_points.push_back(i);
        }
    }

    return articulation_points;
}
