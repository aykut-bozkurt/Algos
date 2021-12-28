#include <algorithm>
#include <stack>
#include <utility>

template<class Iter>
Iter partition(Iter start, Iter end) {
    // pick pivot as last element
    auto pivot_it = end;

    auto cur_it = start;
    auto swap_it = start;
    while(cur_it < end){
        if(*cur_it < *pivot_it){
            // put lower elements before greater ones
            std::iter_swap(cur_it, swap_it);
            swap_it++;
        }

        cur_it++;
    }

    // put pivot in its place
    std::iter_swap(swap_it, pivot_it);

    return swap_it;
}

template<class Iter>
void quick_sort(Iter start, Iter end){
    if(start < end){
        // find partition point
        auto partition_it = partition(start, end);

        // recur for other subparts
        quick_sort(start, partition_it - 1);
        quick_sort(partition_it + 1, end);
    }
}

template<class Iter>
void iterative_quick_sort(Iter start, Iter end){
    std::stack<std::pair<Iter,Iter>> subparts;
    subparts.push({start, end});

    while(!subparts.empty()){
        auto [lo_it, hi_it] = subparts.top();
        subparts.pop();

        if(lo_it < hi_it){
            // find partition point
            auto partition_it = partition(lo_it, hi_it);

            subparts.push({lo_it, partition_it - 1});
            subparts.push({partition_it + 1, hi_it});
        }
    }
}
