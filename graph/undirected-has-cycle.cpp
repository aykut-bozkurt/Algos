#include "undirected-has-cycle.h"

#include <stack>
#include <iostream>

static bool DFS(Graph& g, int cur_idx, int parent_idx, bool (&visited)[4], std::stack<int> path){
    if(!visited[cur_idx]){
        visited[cur_idx] = true;
        // add to path
        path.push(cur_idx);

        for(auto& adj_idx : g.get_adj(cur_idx)){
            // if adj vertex is not visited yet and there is a back edge in further depth; (go down in depth)
            if(!visited[adj_idx]){
                if(DFS(g, adj_idx, cur_idx, visited, path)){
                    return true;
                }
            }
            // else if there is an edge from adj vertex to a previsited vertex that is not parent
            else if(adj_idx != parent_idx){
                // found cycle, print path and return true
                std::stack<int> reverse_path;
                while(!path.empty()){
                    reverse_path.push(path.top());
                    path.pop();
                }
                while(!reverse_path.empty()){
                    std::cout << reverse_path.top() << " -> ";
                    reverse_path.pop();
                }
                std::cout << adj_idx << std::endl;

                return true;
            }
        }

        // remove vertex from path if no adj vertex is left; (go up in depth)
        path.pop();
    }

    return false;
}

bool undirected_has_cycle(Graph& g){
    bool visited[4] = {false};
    std::stack<int> path;

    return DFS(g, 0, -1, visited, path);
}

