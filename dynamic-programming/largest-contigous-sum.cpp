#include "largest-contigous-sum.h"

int largest_contigous_sum(const std::vector<int>& a){
    int sol[a.size()][a.size()];
    for(std::size_t i = 0; i < a.size(); i++){
        for(std::size_t j = 0; j < a.size(); j++){
            if(i == j){
                sol[i][j] = a[i];
            }
            else{
                sol[i][j] = 0;
            }
        }
    }

    auto max_contigous_sum = 0;
    // for each end index
    for(std::size_t i = 1; i < a.size(); i++){
        // for each start index
        for(std::size_t j = 0; j < i; j++){
            sol[i][j] = std::max(sol[i][j], sol[i][j-1] + a[j]);
            if(sol[i][j] > max_contigous_sum){
                max_contigous_sum = sol[i][j];
            }
        }
    }

    return max_contigous_sum;
}