#include "knight-tour.h"

#include <iostream>
#include <utility>
#include <vector>
#include <iomanip>

static void print_tour(int (&visited)[8][8]){
    for(std::size_t i = 0; i < 8; i++){
        for(std::size_t j = 0; j < 8; j++){
            std::cout << std::setw(2) << visited[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

static inline bool is_safe_move(int (&visited)[8][8], int x, int y){
    return (visited[x][y] == -1) && (x >= 0) && (x < 8) && (y >= 0) && (y < 8);
}

static int x_move[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
static int y_move[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int knight_tour(int (&visited)[8][8], int total_visited, int cur_x, int cur_y){
    if(total_visited == 64){
        print_tour(visited);
        return 1;
    }

    // recurse for each next point by incrementing total visited count
    for(std::size_t i = 0; i < 8; i++){
        auto next_x = cur_x + x_move[i];
        auto next_y = cur_y + y_move[i];

        if(is_safe_move(visited, next_x, next_y)){
            visited[next_x][next_y] = total_visited;
            total_visited++;

            if(knight_tour(visited, total_visited, next_x, next_y)){
                // stop if valid config is found
                return 1;
            }

            total_visited--;
            visited[next_x][next_y] = -1;
        }
    }

    return 0;
}
