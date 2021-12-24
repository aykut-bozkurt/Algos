#include <algorithm>

template<class Iter>
void bubble_sort(Iter start, Iter end){
    auto size = std::distance(start, end);
    if(size == 1){
        return;
    }

    for(size_t i = 0; i < size; i++){
        bool any_swapped = false;

        for(auto it = start; it != std::prev(end) - i; ++it){
            if(*std::next(it) < *it){
                any_swapped = true;
                std::iter_swap(it, std::next(it));
            }
        }

        if(!any_swapped){
            break;
        }
    }
}