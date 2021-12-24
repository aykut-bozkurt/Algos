#include "e-to-x.h"

#include <cinttypes>

float e_to_x(const int x){
    // taylor_Exp: e_x = x_0/0! + x_1/1! + x_2/2! + ...
    std::size_t terms = 0;
    float factorial_term = 1;
    float power_term = 1;
    float approx_ans = 0;

    // use 10 terms for approximation
    while(terms <= 10){
        approx_ans += power_term / factorial_term;
        terms++;
        factorial_term *= terms;
        power_term *= x;
    }

    return approx_ans;
}
