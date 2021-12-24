#include "m-color.h"

#include <cinttypes>
#include <iostream>

static void print_coloring(const int (&sol)[4]){
    for(std::size_t i = 0; i < 4; i++){
            std::cout << sol[i] << " ";
    }
    std::cout << std::endl;
}

static inline bool is_safe_color(const int (&graph)[4][4], int (&sol)[4], const int color, const int colored_node){
    // already colored
    if(sol[colored_node] != 0){
        return false;
    }

    // cannot be colored with the same color with any adjacent node
    for(std::size_t i = 0; i < 4; i++){
        if((graph[colored_node][i] == 1) && (color == sol[i])){
            return false;
        }
    }

    return true;
}

bool m_color(const int (&graph)[4][4], int (&sol)[4], int total_colored, const int m){
    if(total_colored == 4){
        print_coloring(sol);
        return true;
    }

    for(std::size_t i = 0; i < 4; i++){
        for(std::size_t color = 1; color <= m; color++){
            if(is_safe_color(graph, sol, color, i)){
                sol[i] = color;
                total_colored++;

                if(m_color(graph, sol, total_colored, m)){
                    return true;
                }

                total_colored--;
                sol[i] = 0;
            }
        }
    }

    return false;
}
