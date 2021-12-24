#include "square-root.h"

long square_root_floor(long n){
    // O(logn)
    if(n == 0 || n == 1){
        return n;
    }

    int start_n = 2;
    int end_n = n / 2;
    int mid;
    int ans;
    while(start_n * start_n < n){
        mid = (start_n + end_n) / 2;

        if(mid * mid == n){
            return mid;
        }
        else if(mid * mid < n){
            start_n = mid + 1;
            ans = mid;
        }
        else{
            end_n = mid - 1;
            ans = mid;
        }
    }

    return mid;
}
