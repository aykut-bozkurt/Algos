#include "largest-even-sum.h"

#include <algorithm>

int largest_even_sum(std::vector<int>& vec, const int k){
    // sort elements
    std::sort(vec.begin(), vec.end(), std::greater<int>());

    // fill odds and evens in descending order separately
    std::vector<int> odds;
    std::vector<int> evens;
    for(auto& el : vec){
        if(el % 2 == 0){
            evens.push_back(el);
        }
        else{
            odds.push_back(el);
        }
    }

    int odd_idx = 0;
    int even_idx = 0;
    int count = 0;
    int sum = 0;

    // compare 2 odds' summation is bigger than 2 evens' summation and add numbers if valid
    while((count + 2) <= k && odd_idx < odds.size() - 1 && even_idx < evens.size() - 1){
        if(evens[even_idx] + evens[even_idx + 1] < odds[odd_idx] + odds[odd_idx + 1]){
            sum += evens[even_idx] + evens[even_idx + 1];
            even_idx += 2;
        }
        else{
            sum += odds[odd_idx] + odds[odd_idx + 1];
            odd_idx += 2;
        }
        count += 2;
    }

    // 2 by 2 add left odds if valid
    while((count + 2) <= k && odd_idx < odds.size() - 1){
        sum += odds[odd_idx] + odds[odd_idx + 1];
        odd_idx += 2;
        count += 2;
    }

    // 1 by 1 add left evens if valid
    while((count + 1) <= k && even_idx < evens.size()){
        sum += evens[even_idx];
        even_idx += 1;
        count += 1;
    }

    return sum ? sum : -1;
}
