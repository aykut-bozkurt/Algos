#include <algorithm>
#include <iostream>

template<class Iter>
void insert(Iter start, Iter unsorted_it, int gap){
    auto inserted_val = *unsorted_it;
    auto cur_it = unsorted_it - gap;
    while(cur_it >= start && *cur_it > inserted_val){
        *(cur_it + gap) = *(cur_it);
        cur_it -= gap;
    }
    *(cur_it + gap) = inserted_val;
}

template<class Iter>
void shell_sort(Iter start, Iter end){
    using val_type = typename Iter::value_type;

    int size = std::distance(start, end);
    if(size < 2){
        return;
    }

    // when gap=1 it is same with nearly sorted insertion sort
    for(int gap = size / 2; gap >= 1; gap /= 2){
        auto unsorted_it = start + gap;
        while(unsorted_it < end){
            insert(start, unsorted_it);
            unsorted_it += gap;
        }
    }
}
