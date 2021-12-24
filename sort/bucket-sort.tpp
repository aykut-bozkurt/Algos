#include <algorithm>
#include <vector>

template<class Iter>
void bucket_sort(Iter start, Iter end){
    using val_type = typename Iter::value_type;

    // create empty buckets
    std::size_t total_buckets = std::distance(start, end);
    std::vector<std::vector<val_type>> buckets(total_buckets);

    // fill the buckets O(n)
    auto cur_it = start;
    while(cur_it != end){
        buckets[(int) (*cur_it * total_buckets)].push_back(*cur_it);
        cur_it++;
    }

    // sort the buckets; O(n) if numbers are uniformly distributed because ever bucket contains 1 element; O(n2) in worst case if all goes into same bucket
    int idx = 0;
    cur_it = start;
    for(std::size_t i = 0; i < total_buckets; i++){
        std::sort(buckets[i].begin(), buckets[i].end());
        for(auto& el : buckets[i]){
            *cur_it = el;
            cur_it++;
            idx++;
        }
    }
}
