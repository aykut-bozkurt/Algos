#include "power.h"

#include <cinttypes>

long special_power(int a, int b){
    if(b == 0){
        return 1;
    }

    int ans = a;
    int increment = a;

    for(std::size_t i = 1; i < b; i++){
        for(std::size_t i = 1; i < a; i++){
            ans += increment;
        }
        increment = ans;
    }

    return ans;
}
