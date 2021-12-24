#include "matrix-chain-multiplication.h"

#include <cinttypes>
#include <algorithm>

int matrix_chain_multiplication(const std::vector<int>& dims){
    int sol[dims.size()] = {0};
    sol[1] = 0;
    sol[2] = dims[0] * dims[1] * dims[2];

    for(std::size_t i = 3; i < dims.size(); i++){
        // using (A.B).C
        auto sol1 = sol[i-1] + dims[0] * dims[i-1] * dims[i];
        // using A.(B.C)
        auto sol2 = sol[i-2] + dims[i-2] * dims[i-1] * dims[i] + dims[0] * dims[i-2] * dims[i];

        sol[i] = std::min(sol1, sol2);
    }

    return sol[dims.size()-1];
}
