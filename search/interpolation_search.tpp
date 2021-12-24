#include <algorithm>

#include "linear_search.h"

template<class Iter, class T>
bool interpolation_search(Iter start, Iter end, T&& val){
    if(start == end){
        return false;
    }
    else if(val < *start){
        return false;
    }
    else if(val > *std::prev(end)){
        return false;
    }
    else{
        // add prev 2 cases bacause now we will assume the value is between low and high values while calculating middle point
        auto index_range = std::distance(start, end);
        auto val_range = *std::prev(end) - *start;
        size_t mid_distance = ((double)(val - *start) / val_range) * (index_range - 1);
        auto mid = std::next(start, mid_distance);

        if(*mid == val){
            return true;
        }
        else if(*mid < val){
            return interpolation_search(start, mid, val);
        }
        else{
            return interpolation_search(std::next(mid), end, val);
        }
    }
}


