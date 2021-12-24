#include <algorithm>

static int get_next_gap(int gap){
    gap = gap * 10 / 13;
    if(gap < 1){
        return 1;
    }

    return gap;
}

template<class Iter>
void comb_sort(Iter start, Iter end){
    auto size = std::distance(start, end);
    if(size == 1){
        return;
    }

    bool any_swapped = false;
    int gap = size;
    // if any swap occurs continue sorting
    // if gap not equal 1, continue sorting
    // shrink factor 1.3 is emprically the best
    while(gap != 1 || any_swapped){
        gap = get_next_gap(gap);
        any_swapped = false;

        for(auto it = start; it != std::prev(end, gap); ++it){
            if(*std::next(it, gap) < *it){
                any_swapped = true;
                std::iter_swap(it, std::next(it, gap));
            }
        }
    }
}