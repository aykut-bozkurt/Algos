#include <algorithm>

template<class Iter, class T>
bool linear_search(Iter start, Iter end, T&& val){
    while(start != end){
        if(*start == val){
            return true;
        }

        std::advance(start, 1);
    }

    return false;
}

