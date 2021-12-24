#include "rat-in-maze.h"

#include <cinttypes>
#include <iostream>
#include <iomanip>

static void print_route(const int (&visited)[4][4]){
    for(std::size_t i = 0; i < 4; i++){
        for(std::size_t j = 0; j < 4; j++){
            std::cout << std::setw(2) << visited[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

static inline bool is_safe_move(const int (&maze)[4][4], int x, int y){
    return maze[x][y] == 1 && x < 4 && y < 4;
}

// only right and down moves allowed
static int x_moves[2] = {1, 0};
static int y_moves[2] = {0, 1};

int rat_in_maze(const int (&maze)[4][4], int (&sol)[4][4], int cur_x, int cur_y){
    if(cur_x == 3 && cur_y == 3){
        print_route(sol);
        return 1;
    }

    for(std::size_t i = 0; i < 2; i++){
        auto next_x = cur_x + x_moves[i];
        auto next_y = cur_y + y_moves[i];

        if(is_safe_move(maze, next_x, next_y)){
            sol[next_x][next_y] = 1;

            if(rat_in_maze(maze, sol, next_x, next_y)){
                return 1;
            }

            sol[next_x][next_y] = 0;
        }
    }

    return 0;
}
