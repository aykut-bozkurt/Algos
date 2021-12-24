#include "power.h"

int power(int base, int to){
    if(to == 0){
        return 1;
    }
    else if(to % 2 == 1){
        return base * power(base, to - 1);
    }
    else{
        int res = power(base, to/2);
        return res * res;
    }
}
