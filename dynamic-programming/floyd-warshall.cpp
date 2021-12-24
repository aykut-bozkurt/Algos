#include "floyd-warshall.h"

#include <cinttypes>
#include <iostream>
#include <iomanip>

void floyd_warshall(int (&graph)[4][4]){
    int distances[4][4];
    for(std::size_t i = 0; i < 4; i++){
        for(std::size_t j = 0; j < 4; j++){
            distances[i][j] = graph[i][j];
        }
    }

    // for each src
    for(std::size_t i = 0; i < 4; i++){
        // for each dst
        for(std::size_t j = i+1; j < 4; j++){
            // for each mid point
            for(std::size_t k = 0; k < 4; k++){
                if(distances[i][k] != INT32_MAX && distances[k][j] != INT32_MAX){
                    if(distances[i][k] + distances[k][j] < distances[i][j]){
                        distances[i][j] = distances[i][k] + distances[k][j];
                    }
                }
            }
        }
    }

    for(std::size_t i = 0; i < 4; i++){
        for(std::size_t j = 0; j < 4; j++){
           std::cout << std::setw(5) << (distances[i][j] == INT32_MAX ? "INF" : std::to_string(distances[i][j])) << " ";
        }
        std::cout << std::endl;
    }
}
