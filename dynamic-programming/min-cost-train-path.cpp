#include "min-cost-train-path.h"

#include <cinttypes>

int min_cost_train_path(const int (&cost)[4][4]){
    int dist[4];
    for(std::size_t j = 0; j < 4; j++){
        dist[j] = INT32_MAX;
    }
    dist[0] = 0;

    // for each start station
    for(std::size_t i = 0; i < 4; i++){
        // for each end station
        for(std::size_t j = i+1; j < 4; j++){
            if(dist[j] > cost[i][j] + dist[i]){
                dist[j] = cost[i][j] + dist[i];
            }
        }
    }

    return dist[3];
}
