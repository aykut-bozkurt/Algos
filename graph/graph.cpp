#include "graph.h"

#include <algorithm>
#include <iostream>

std::list<int>& Graph::get_adj(int v) {
    return adj[v];
}

void Graph::add_vertex(int v){
    // O(V)
    if(!has_vertex(v)){
        adj.insert(std::next(adj.begin(), v), std::list<int>());
    }
    else{
        std::cout << v << " already added!" << std::endl;
    }
}

void Graph::remove_vertex(int v){
    // O(V . E)
    if(has_vertex(v)){
        // remove vertex
        adj.erase(std::next(adj.begin(), v));

        // remove all other edges to vertex
        for(std::size_t i = 0; i < size(); i++){
            if(has_edge(i, v)){
                remove_edge(i, v);
            }
        }
    }
    else{
        std::cout << v << " already removed!" << std::endl;
    }
}

bool Graph::has_vertex(int v){
    // O(1)
    return adj.size() > v;
}

std::size_t Graph::size(){
    // O(1)
    return adj.size();
}

void Graph::add_edge(int v1, int v2){
    // O(E)
    if(has_vertex(v1) && has_vertex(v2)){
        if(!has_edge(v1, v2)){
            auto src_vertex = adj.begin();
            std::advance(src_vertex, v1);
            src_vertex->push_back(v2);
        }
        else{
            std::cout << "Edge " << v1 << "-" << v2 << " already added!" << std::endl;
        }
    }
    else{
        std::cout << "At least one of the vertices not found to add edge!" << std::endl;
    }
}

void Graph::add_undirected_edge(int v1, int v2){
    // O(E)
    add_edge(v1, v2);
    add_edge(v2, v1);
}

void Graph::remove_edge(int v1, int v2){
    // O(E)
    if(has_vertex(v1) && has_vertex(v2)){
        auto src_vertex = adj.begin();
        std::advance(src_vertex, v1);
        auto edge_it = std::find(src_vertex->begin(), src_vertex->end(), v2);
        if(edge_it != src_vertex->end()){
            src_vertex->erase(edge_it);
        }
        else{
            std::cout << "Edge " << v1 << "-" << v2 << " already removed!" << std::endl;
        }
    }
    else{
        std::cout << "At least one of the vertices not found to remove edge!" << std::endl;
    }
}

bool Graph::has_edge(int v1, int v2){
    // O(E)
    if(has_vertex(v1) && has_vertex(v2)){
        auto src_vertex = adj.begin();
        std::advance(src_vertex, v1);
        auto edge_it = std::find(src_vertex->begin(), src_vertex->end(), v2);
        if(edge_it != src_vertex->end()){
            return true;
        }
    }

    return false;
}
