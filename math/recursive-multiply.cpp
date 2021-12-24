#include "recursive-multiply.h"

long multiply_special(long x, long y){
    if(y == 0){
        return 0;
    }
    else if(y < 0){
        return -multiply_special(x, -y);
    }
    else{
        return x + multiply_special(x, y - 1);
    }
}
