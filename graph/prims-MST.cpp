#include "prims-MST.h"
#include "disjoint-set.h"

#include <queue>
#include <stack>
#include <iostream>

static void print_MST(int (&parent)[4]){
    for (int i = 1; i < 4; i++){
        std::cout << parent[i] << " - " << i << std::endl;
    }
}

int get_min_vertex(bool (&mst_set)[4], int (&weight)[4]){
    int min_idx = -1;
    int min_weight = INT32_MAX;
    for(std::size_t i = 0; i < 4; i++){
        if(!mst_set[i] && weight[i] < min_weight){
            min_weight = weight[i];
            min_idx = i;
        }
    }
    return min_idx;
}

void prims(GraphWithEdge& g){
    bool mst_set[4] = {false};
    int weight[4];
    int parent[4];
    for(std::size_t i = 0; i < 4; i++) {
        weight[i] = INT32_MAX;
        parent[i] = -1;
    }
    weight[0] = 0;

    // MST will contain V - 1 edges if exists
    for(std::size_t edge_count = 0; edge_count < 3; edge_count++) {
        // get min edge weighted non-mst vertex and add it to mst set
        auto current_idx = get_min_vertex(mst_set, weight);
        mst_set[current_idx] = true;

        for(auto& edge : g.get_adj(current_idx)){
            // update edge weight of any vertex adjacent to current mst node that is not in current mst
            if (!mst_set[edge.dst] && edge.weight < weight[edge.dst]){
                weight[edge.dst] = edge.weight;
                parent[edge.dst] = edge.src;
            }
        }
    }

    print_MST(parent);
}
