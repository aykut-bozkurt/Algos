#include <algorithm>

template<class Iter>
void counting_sort(Iter start, Iter end){
    auto size = std::distance(start, end);
    auto max = *std::max_element(start, end);

    using val_type = typename Iter::value_type;

    // count freqs
    val_type counts[max+1] = {0};
    std::for_each(start, end, [&](const auto& elem){
        counts[elem]++;
    });

    // store positions for numbers
    for(std::size_t i = 1; i <= max; i++){
        counts[i] += counts[i-1];
    }

    // populate auxilary array using real array
    val_type output[size] = {0};
    auto cur_it = start;
    for(std::size_t i = 0; i < size; i++){
        output[counts[*cur_it] - 1] = *cur_it;
        counts[*cur_it]--;
        cur_it++;
    }

    // populate real array
    cur_it = start;
    for(std::size_t i = 0; i < size; i++){
        *cur_it = output[i];
        cur_it++;
    }
}