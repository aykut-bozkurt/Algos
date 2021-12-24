#include "bisection-root.h"

#include <cmath>

static double func(double x)
{
    return x*x*x - x*x + 2;
}

double bisection(double a, double b){
    const auto EPSILON = 0.00001;
    auto c = 0.0;
    auto y_a = func(a);
    auto y_b = func(b);

    while(std::abs(a - b) >= EPSILON){
        c = (a + b) / 2;

        if(func(c) == 0){
            // root is c
            break;
        }
        else if(func(a) * func(c) < 0){
            // root is btw a and c
            b = c;
        }
        else{
            // root is btw b and c
            a = c;
        }
    }

    return c;
}
