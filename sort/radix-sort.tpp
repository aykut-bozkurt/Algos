#include <algorithm>

#include "counting-sort.h"

template<class Iter>
void counting_sort(Iter start, Iter end, int exp){
    auto size = std::distance(start, end);

    using val_type = typename Iter::value_type;

    // count freqs
    val_type counts[10] = {0};
    std::for_each(start, end, [&](const auto& elem){
        counts[(elem / exp) % 10]++;
    });

    // store positions for numbers
    for(std::size_t i = 1; i <= 9; i++){
        counts[i] += counts[i-1];
    }

    // populate auxilary array using real array
    val_type output[size] = {0};
    // should start with last idx, because last elements are greater if next digits are the same
    for(std::ptrdiff_t i = size-1; i >= 0; i--){
        output[counts[(*(start + i) / exp) % 10] - 1] = *(start + i);
        counts[(*(start + i) / exp) % 10]--;
    }

    // populate real array
    auto cur_it = start;
    for(std::size_t i = 0; i < size; i++){
        *cur_it = output[i];
        cur_it++;
    }
}

template<class Iter>
void radix_sort(Iter start, Iter end){
    auto size = std::distance(start, end);
    auto max = *std::max_element(start, end);
    auto exp = 1;
    while(max > 0){
        counting_sort(start, end, exp);

        max /= 10;
        exp *= 10;
    }
}
