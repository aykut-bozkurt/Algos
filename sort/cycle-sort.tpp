#include <algorithm>

template<class Iter>
Iter get_sorted_position(Iter start, Iter end, typename Iter::value_type item) {
    auto sorted_position = start;
    int sorted_idx = 0;
    while(sorted_position != end){
        if(*sorted_position < item){
            sorted_idx++;
        }
        sorted_position++;
    }

    return start + sorted_idx;
}

template<class Iter>
void cycle_sort(Iter start, Iter end){
    for(auto cycle_it = start; cycle_it != end; cycle_it++){
        // find the position of the current item in sorted array and move it until a cycle is completed ; if it is already in correct position, then no operation
        typename Iter::value_type cur_item = *cycle_it;
        Iter next_it = get_sorted_position(start, end, cur_item);

        while(next_it != cycle_it){
            // swap the next item to find sorted position and sorted position value
            std::swap(cur_item, *next_it);

            // iterator to sorted position for current item
            next_it = get_sorted_position(start, end, cur_item);

            if(next_it == cycle_it){
                std::swap(cur_item, *next_it);
            }
        }
    }
}