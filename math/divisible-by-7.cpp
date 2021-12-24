#include "divisible-by-7.h"

bool is_divisible_by_7(const int n){
    if(n < 0){
        // n is negative
        return is_divisible_by_7(-n);
    }
    else if(n == 0 || n == 7){
        // n is divisible by 7
        return true;
    }
    else if(n < 10){
        // n is not divisible by 7
        return false;
    }
    else{
        // recur for the formula (remaining_digits - 2 * last digit) without using modulo
        auto remaining_digit = n / 10;
        auto last_digit = n - remaining_digit * 10;
        return is_divisible_by_7(remaining_digit - 2 * last_digit);
    }
}
