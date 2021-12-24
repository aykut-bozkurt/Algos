#include <algorithm>
#include <cmath>

#include "linear_search.h"

namespace details{
 template<class Iter, class T>
 bool jump_search(Iter start, Iter end, const size_t jump_size, T&& val){
     if(start == end){
         return false;
     }

     if(jump_size <= std::distance(start, end)){
         return linear_search(start, end, val);
     }
     else{
         auto next_start = std::next(start, jump_size);
         if(val == *next_start){
             return true;
         }
         else if(val < *next_start){
             return linear_search(start, next_start, val);
         }
         else{
             return jump_search(next_start, end, jump_size, val);
         }
     }
 }
}

template<class Iter, class T>
bool jump_search(Iter start, Iter end, T&& val){
    std::size_t optimal_jump_size = std::floor(std::sqrt(std::distance(start, end)));
    return details::jump_search(start, end, optimal_jump_size, val);
}
