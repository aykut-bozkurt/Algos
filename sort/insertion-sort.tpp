#include <algorithm>
#include <iostream>

template<class Iter>
void insert(Iter start, Iter unsorted_it){
    auto inserted_val = *unsorted_it;
    auto cur_it = unsorted_it - 1;
    while(cur_it >= start && *cur_it > inserted_val){
        *(cur_it + 1) = *(cur_it);
        cur_it--;
    }
    *(cur_it + 1) = inserted_val;
}

template<class Iter>
void insertion_sort(Iter start, Iter end){
    using val_type = typename Iter::value_type;

    int size = std::distance(start, end);
    if(size < 2){
        return;
    }

    auto unsorted_it = start + 1;
    while(unsorted_it != end){
        insert(start, unsorted_it);
        unsorted_it++;
    }
}
