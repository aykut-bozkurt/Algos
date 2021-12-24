#include "n-queens.h"

#include <cinttypes>
#include <iostream>
#include <iomanip>

static void print_board(const int (&board)[4][4]){
    for(std::size_t i = 0; i < 4; i++){
        for(std::size_t j = 0; j < 4; j++){
            std::cout << std::setw(2) << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

static inline bool is_safe_place(const int (&board)[4][4], int x, int y){
    // empty check
    if(board[x][y] == 1){
        return false;
    }

    // row collision check
    for(std::size_t i = 0; i < 4; i++){
        if(board[x][i] == 1){
            return false;
        }
    }

    // column collision check
    for(std::size_t i = 0; i < 4; i++){
        if(board[i][y] == 1){
            return false;
        }
    }

    // left up diagonal collision check
    int cur_x_lu = x-1;
    int cur_y_lu = y-1;
    while(cur_x_lu >= 0 && cur_y_lu >= 0){
        if(board[cur_x_lu][cur_y_lu] == 1){
            return false;
        }
        cur_x_lu--;
        cur_y_lu--;
    }

    // left down diagonal collision check
    int cur_x_ld = x-1;
    int cur_y_ld = y+1;
    while(cur_x_ld >= 0 && cur_y_ld < 4){
        if(board[cur_x_ld][cur_y_ld] == 1){
            return false;
        }
        cur_x_ld--;
        cur_y_ld++;
    }

    // right up diagonal collision check
    int cur_x_ru = x+1;
    int cur_y_ru = y-1;
    while(cur_x_ru < 4 && cur_y_ru >= 0){
        if(board[cur_x_ru][cur_y_ru] == 1){
            return false;
        }
        cur_x_ru++;
        cur_y_ru--;
    }

    // right down diagonal collision check
    int cur_x_rd = x+1;
    int cur_y_rd = y+1;
    while(cur_x_rd < 4 && cur_y_rd < 4){
        if(board[cur_x_rd][cur_y_rd] == 1){
            return false;
        }
        cur_x_rd++;
        cur_y_rd++;
    }

    return true;
}

int n_queens(int (&board)[4][4], int placed_queens){
    if(placed_queens == 4){
        print_board(board);
        return 1;
    }

    for(std::size_t i = 0; i < 4; i++){
        for(std::size_t j = 0; j < 4; j++){
            if(is_safe_place(board, i, j)){
                board[i][j] = 1;
                placed_queens++;

                if(n_queens(board, placed_queens)){
                    return 1;
                }

                placed_queens--;
                board[i][j] = 0;
            }
        }
    }

    return 0;
}
