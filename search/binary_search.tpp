#include <algorithm>

template<class Iter, class T>
bool binary_search(Iter start, Iter end, T&& val){
    if(start == end){
        return false;
    }

    auto mid = std::next(start, std::distance(start, end) / 2);
    if(val == *mid){
        return true;
    }
    else if(val < *mid){
        return binary_search(start, mid, val);
    }
    else{
        return binary_search(std::next(mid), end, val);
    }
}
