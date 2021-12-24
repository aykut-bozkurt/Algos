#include "max-profit-transactions.h"

#include <cinttypes>

struct Price{
    int prx;
    std::size_t idx;
};

// 1.buy->sell 2.buy->sell , 2 allowed transactions of buy and sell, and first transaction sohuld end before second, wwhat is max profit
int max_profit_transactions(const std::vector<int>& prices){
    Price max_prices[prices.size()][prices.size()];
    Price min_prices[prices.size()][prices.size()];

    for(std::size_t i = 0; i < prices.size(); i++){
        for(std::size_t j = 0; j < prices.size(); j++){
            if(i == j){
                max_prices[i][j] = {prices[i], i};
                min_prices[i][j] = {prices[i], i};
            }
            else{
                max_prices[i][j] = {INT32_MIN,0};
                min_prices[i][j] = {INT32_MAX,0};
            }
        }
    }

    // for each end index
    for(std::size_t i = 1; i < prices.size(); i++){
        // for each start index
        for(std::size_t j = 0; j <= i; j++){
            if(prices[i] > max_prices[i-1][j].prx){
                max_prices[i][j] = {prices[i], i};
            }
            else{
                max_prices[i][j] = max_prices[i-1][j];
            }

            if(prices[i] < min_prices[i-1][j].prx){
                min_prices[i][j] = {prices[i], i};
            }
            else{
                min_prices[i][j] = min_prices[i-1][j];
            }
        }
    }

    int max_so_far = 0;
    // for each start index
    for(std::size_t i = 0; i < prices.size(); i++){
        // for each middle index
        for(std::size_t j = i; j < prices.size()-1; j++){
            auto max_profit_1 = 0;
            auto max_profit_2 = 0;
            if(max_prices[j][i].idx > min_prices[j][i].idx){
                max_profit_1 = max_prices[j][i].prx - min_prices[j][i].prx;
            }
            if(max_prices[prices.size()-1][j+1].idx > min_prices[prices.size()-1][j+1].idx){
                max_profit_2 = max_prices[prices.size()-1][j+1].prx - min_prices[prices.size()-1][j+1].prx;
            }
            auto candid_max_profit = max_profit_1 + max_profit_2;

            if(max_so_far < candid_max_profit){
                max_so_far = candid_max_profit;
            }
        }
    }

    return (max_so_far < 0) ? 0 : max_so_far;
}
