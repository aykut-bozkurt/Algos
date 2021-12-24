#include "has-path.h"

#include <stack>
#include <iostream>

static bool DFS(Graph& g, bool (&visited)[4], int cur_idx, int dst_idx, std::stack<int>& path){
    visited[cur_idx] = true;
    path.push(cur_idx);

    if(cur_idx == dst_idx){
        return true;
    }

    for(auto& adj_idx : g.get_adj(cur_idx)){
        if(!visited[adj_idx] && DFS(g, visited, adj_idx, dst_idx, path)){
            return true;
        }
    }

    path.pop();

    return false;
}

bool has_path(Graph& g, int v1, int v2){
    std::stack<int> path;
    bool visited[4] = {false};
    bool res = DFS(g, visited, v1, v2, path);

    while(!path.empty()){
        std::cout << path.top();
        path.pop();
        if(!path.empty()){
            std::cout << " <- ";
        }
    }
    std::cout << std::endl;

    return res;
}
