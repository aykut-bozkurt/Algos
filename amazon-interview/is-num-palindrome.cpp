#include "is-num-palindrome.h"

#include <string>

bool is_palindrome(const int n){
    // O(log num)
    std::string num = std::to_string(n);

    for(int i = 0; i < num.size() / 2; i++){
        if(num[i] != num[num.size() - i - 1]){
            return false;
        }
    }

    return true;
}
