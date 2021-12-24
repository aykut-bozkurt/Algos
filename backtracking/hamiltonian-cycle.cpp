#include "hamiltonian-cycle.h"

#include <cinttypes>
#include <iostream>

static void print_hamiltonian_cycle(const int (&sol)[5]){
    for(std::size_t i = 0; i < 5; i++){
        std::cout << sol[i] << " ";
    }
    std::cout << sol[0] << std::endl;
}

static inline bool is_safe_move(const int (&graph)[5][5], const int (&visited)[5], int (&sol)[5], const int next_idx, const int total_vertex){
    return (total_vertex == 0) || ((graph[sol[total_vertex-1]][next_idx] == 1) && (visited[next_idx] == 0));
}

bool hamiltonian_cycle(const int (&graph)[5][5], int (&visited)[5], int (&sol)[5], int total_vertex){
    if(total_vertex == 5){
        if(graph[sol[4]][sol[0]]){
            print_hamiltonian_cycle(sol);
            return true;
        }
        else{
            return false;
        }
    }

    for(std::size_t i = 0; i < 5; i++){
        if(is_safe_move(graph, visited, sol, i, total_vertex)){
            visited[i] = 1;
            sol[total_vertex] = i;
            total_vertex++;

            if(hamiltonian_cycle(graph, visited, sol, total_vertex)){
                return true;
            }

            total_vertex--;
            sol[total_vertex] = -1;
            visited[i] = 0;
        }
    }

    return false;
}
