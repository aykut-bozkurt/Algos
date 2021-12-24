#include <algorithm>

template<class Iter>
void selection_sort(Iter start, Iter end){
    auto unsorted = start;
    while(unsorted != end){
        auto min_it = std::min_element(unsorted, end);
        std::iter_swap(unsorted, min_it);
        ++unsorted;
    }
}