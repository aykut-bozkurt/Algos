#include "find-max.h"

#include <algorithm>

int find_max(const std::vector<int>& a, std::size_t left, std::size_t right){
    if(left == right){
        return a[left];
    }
    else{
        // divide
        std::size_t middle = (left + right) / 2;

        // conquer
        int max1 = find_max(a, left, middle);
        int max2 = find_max(a, middle+1, right);

        // combine
        return std::max(max1, max2);
    }
}
