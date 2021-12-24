#include "birthday-paradox.h"

float birthday_paradox(int n){
    // p(same) = 1 - p(different)
    const int total_days = 365;
    if(n > total_days){
        return 1;
    }

    // 1 person is assigned a day
    n--;

    float p_different = 1;
    int unassigned_days = 364;
    while(n > 0){
        p_different = p_different *  unassigned_days / total_days;
        unassigned_days--;
        n--;
    }

    return 1 - p_different;
}
