#include "median-of-2-array.h"

#include <algorithm>

int median_of_2_array(const std::vector<int>& a, const std::vector<int>& b, int start_idx1, int start_idx2, int end_idx1, int end_idx2){
    if(start_idx1 == end_idx1){
        // combine; average 2 median values for merged list
        return (a[start_idx1] + b[start_idx2]) / 2;
    }
    else if(start_idx1 + 1 == end_idx1){
        // combine; we cannot recurse if range is 2 in both sets, we should average max and min of both ranges to find median for merged list
        return (std::max(a[start_idx1], b[start_idx2]) + std::min(a[end_idx1], b[end_idx2])) / 2;
    }
    else{
        // divide differently when each set has odd or even elements
        int median1 = ((end_idx1 - start_idx1 + 1) % 2 == 1) ? a[(start_idx1 + end_idx1) / 2] : (a[(start_idx1 + end_idx1 + 1) / 2] + a[(start_idx1 + end_idx1 - 1) / 2]) / 2;
        int median2 = ((end_idx2 - start_idx2 + 1) % 2 == 1) ? b[(start_idx2 + end_idx2) / 2] : (b[(start_idx2 + end_idx2 + 1) / 2] + b[(start_idx2 + end_idx2 - 1) / 2]) / 2;

        if(median1 == median2){
            // if both median is same, return it immediately for merged list
            return median1;
        }
        else if(median1 > median2){
            // recurse left of 1. list
            end_idx1 = (start_idx1 + end_idx1) / 2;
            // recurse right of 2. list
            start_idx2 = (start_idx2 + end_idx2 + 1) / 2;
        }
        else{
            // recurse left of 2. list
            end_idx2 = (start_idx2 + end_idx2) / 2;
            // recurse right of 1. list
            start_idx1 = (start_idx1 + end_idx1 + 1) / 2;
        }

        // conquer
        return median_of_2_array(a, b, start_idx1, start_idx2, end_idx1, end_idx2);
    }
}
