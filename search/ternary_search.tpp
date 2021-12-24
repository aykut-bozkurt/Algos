#include <algorithm>

template<class Iter, class T>
bool ternary_search(Iter start, Iter end, T&& val){
    if(start == end){
        return false;
    }

    auto mid1 = std::next(start, std::distance(start, end) / 3);
    auto mid2 = std::next(mid1, std::distance(mid1, end) / 3);
    if(val == *mid1){
        return true;
    }
    else if(val == *mid2){
        return true;
    }
    else if(val < *mid1){
        return ternary_search(start, mid1, val);
    }
    else if(val > *mid2){
        return ternary_search(std::next(mid2), end, val);
    }
    else{
        return ternary_search(std::next(mid1), mid2, val);
    }
}
