#include <algorithm>
#include <vector>

template<class Iter>
void pigeonhole_sort(Iter start, Iter end){
    using val_type = typename Iter::value_type;

    // create empty holes
    auto size = std::distance(start, end);
    auto max = *std::max_element(start, end);
    auto min = *std::min_element(start, end);
    auto range = max - min + 1;
    std::vector<std::vector<val_type>> holes(range);

    // fill holes O(n)
    auto cur_it = start;
    while(cur_it != end){
        holes[*cur_it - min].push_back(*cur_it);
        cur_it++;
    }

    // sort holes O(range) if elements are uniformly distributed ; O(n2) if all elements are in 1 hole
    int idx = 0;
    cur_it = start;
    for(std::size_t i = 0; i < range; i++){
        std::sort(holes[i].begin(), holes[i].end());
        for(auto& el : holes[i]){
            *cur_it = el;
            cur_it++;
        }
    }
}
