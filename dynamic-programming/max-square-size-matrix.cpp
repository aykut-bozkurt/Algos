#include "max-square-size-matrix.h"

#include <cinttypes>
#include <algorithm>

int max_square_size_matrix(const int (&arr)[6][5]) {
    int sol[6][5];
    for (std::size_t i = 0; i < 6; i++) {
        sol[i][0] = (arr[i][0] == 1) ? 1 : 0;
    }
    for (std::size_t i = 0; i < 5; i++) {
        sol[0][i] = (arr[0][i] == 1) ? 1 : 0;
    }

    int max_size = 0;
    for (std::size_t i = 1; i < 6; i++) {
        for (std::size_t j = 1; j < 5; j++) {
            if(arr[i][j] == 1){
                sol[i][j] = std::min({sol[i-1][j], sol[i][j-1], sol[i-1][j-1]}) + 1;
            }
            else{
                sol[i][j] = 0;
            }

            if(sol[i][j] > max_size){
                max_size = sol[i][j];
            }
        }
    }

    return max_size;
}