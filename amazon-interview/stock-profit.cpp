#include "stock-profit.h"

#include <cinttypes>

int max_profit(const std::vector<int>& prices){
    int max_profit = 0;
    int min_element = INT32_MAX;

    // for each end idx
    for(int i = 0; i < prices.size(); i++){
        if(prices[i] < min_element){
            min_element = prices[i];
        }

        if(prices[i] - min_element > max_profit){
            max_profit = prices[i] - min_element;
        }
    }

    return max_profit;
}
