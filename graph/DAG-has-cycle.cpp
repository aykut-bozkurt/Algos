#include "DAG-has-cycle.h"

#include <stack>
#include <iostream>

static bool DFS(Graph& g, int cur_vertex, bool (&visited)[4], bool (&on_path)[4], std::stack<int> path){
    if(!visited[cur_vertex]){
        visited[cur_vertex] = true;
        // add to path
        on_path[cur_vertex] = true;
        path.push(cur_vertex);

        for(auto& adj_idx : g.get_adj(cur_vertex)){
            // if adj vertex is not visited yet and there is a back edge in further depth; (go down in depth)
            if(!visited[adj_idx] && DFS(g, adj_idx, visited, on_path, path)){
                return true;
            }
            // else if there is an edge from adj vertex to a vertex on current path
            else if(on_path[adj_idx]){
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
        on_path[cur_vertex] = false;
        path.pop();
    }

    return false;
}

bool directed_has_cycle(Graph& g){
    bool visited[4] = {false};
    bool on_path[4] = {false};
    std::stack<int> path;

    return DFS(g, 0, visited, on_path, path);
}

