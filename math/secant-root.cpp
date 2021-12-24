#include "secant-root.h"

#include <cmath>

static double func(double x)
{
    return x*x*x - x*x + 2;
}

static double secant_root(double a, double b){
    // assume root is on line between a and b
    // (f(b) - f(a)) / (b - a) = (f(root) - f(a)) / (root - a)    ;    f(root) will be 0
    return ((func(a) * (a - b)) / (func(b) - func(a))) + a;
}

double secant(double a, double b){
    const auto MAX_ITER = 1000000;
    auto iter = 0;
    double c = a;

    while(iter < MAX_ITER){
        c = secant_root(a, b);

        if(func(c) == 0){
            break;
        }
        else if(func(a) * func(c) < 0){
            b = c;
        }
        else{
            a = c;
        }

        iter++;
    }

    return c;
}
