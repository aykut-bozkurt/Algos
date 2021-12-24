#include "lucky-number.h"

bool is_lucky_number(int n){
    // updates position of the n after each removal
    int next_position = n;
    int removal_stride = 2;

    // O(n)
    while(next_position > removal_stride){
        next_position = next_position - next_position / removal_stride;
        removal_stride++;
    }

    if(removal_stride > next_position){
        return true;
    }
    else{
        return false;
    }
}
