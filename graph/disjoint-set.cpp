#include "disjoint-set.h"

DisjointSet::DisjointSet(std::size_t size) {
    this->parents = std::vector<int>(size, -1);
}

int DisjointSet::find(int v) {
    if(parents[v] != -1){
        return find(parents[v]);
    }

    return v;
}

void DisjointSet::uunion(int v1, int v2) {
    int parent1 = find(v1);
    int parent2 = find(v2);

    this->parents[parent2] = parent1;
}