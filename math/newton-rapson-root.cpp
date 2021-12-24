#include "newton-rapson-root.h"

#include <cmath>

static double func(double x)
{
    return x*x*x - x*x + 2;
}

static double deriv_func(double x)
{
    return 3*x*x - 2*x;
}

double newton_rapson(){
    auto x = -20.0;
    const auto EPSILON = 0.00001;
    auto h = func(x) / deriv_func(x);

    while(std::abs(h) >= EPSILON){
        h = func(x) / deriv_func(x);
        x = x - h;
    }

    return x;
}
