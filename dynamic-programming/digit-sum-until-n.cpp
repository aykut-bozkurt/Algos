#include "digit-sum-until-n.h"

#include <cinttypes>

int digit_sum_until_n(const int n){
    int number_digit_sum[n+1];
    number_digit_sum[0] = 0;

    int sum = 0;
    for(std::size_t i = 1; i <= n; i++){
        number_digit_sum[i] = number_digit_sum[i/10] + i%10;
        sum += number_digit_sum[i];
    }

    return sum;
}
