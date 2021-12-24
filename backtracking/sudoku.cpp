#include "sudoku.h"

#include <cinttypes>
#include <iostream>
#include <iomanip>

static void print_sudoku(int (&grid)[9][9]){
    for(std::size_t i = 0; i < 9; i++){
        for(std::size_t j = 0; j < 9; j++){
            std::cout << grid[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

static bool is_safe_assignment(int (&grid)[9][9], int x, int y, int digit){
    // 9x9 row check
    for(std::size_t i = 0; i < 9; i++){
        if(grid[x][i] == digit){
            return false;
        }
    }

    // 9x9 column check
    for(std::size_t i = 0; i < 9; i++){
        if(grid[i][y] == digit){
            return false;
        }
    }

    // 3x3 subgrid check
    std::size_t subgrid_x = x - (x % 3);
    std::size_t subgrid_y = y - (y % 3);
    for(std::size_t i = 0; i < 3; i++){
        for(std::size_t j = 0; j < 3; j++){
            if(grid[i + subgrid_x][j + subgrid_y] == digit){
                return false;
            }
        }
    }

    return true;
}

static bool find_unassigned_location(int (&grid)[9][9], std::size_t& x, std::size_t& y){
    for(std::size_t i = 0; i < 9; i++){
        for(std::size_t j = 0; j < 9; j++){
            if(grid[i][j] == 0){
                x = i;
                y = j;
                return true;
            }
        }
    }

    return false;
}

static bool sudoku(int (&grid)[9][9], int total_assigned){
    if(total_assigned == 81){
        print_sudoku(grid);
        return true;
    }

    std::size_t i;
    std::size_t j;
    find_unassigned_location(grid, i, j);

    for(int digit = 1; digit <= 9; digit++){
        if(is_safe_assignment(grid, i, j, digit)){
            grid[i][j] = digit;
            total_assigned++;

            if(sudoku(grid, total_assigned)){
                return true;
            }

            total_assigned--;
            grid[i][j] = 0;
        }
    }

    return false;
}

bool sudoku(int (&grid)[9][9]){
    int total_assigned = 0;
    for(std::size_t i = 0; i < 9; i++){
        for(std::size_t j = 0; j < 9; j++){
            if(grid[i][j] != 0){
                total_assigned++;
            }
        }
    }

    return sudoku(grid, total_assigned);
}
