#include "base-14-add.h"

#include <map>

std::string base14_add(const std::string& a1, const std::string& a2){
    std::map<int, char> digit_to_base14;
    for(std::size_t i = 0; i <= 9; i++){
        digit_to_base14[i] = '0' + i;
    }
    digit_to_base14[10] = 'A';
    digit_to_base14[11] = 'B';
    digit_to_base14[12] = 'C';
    digit_to_base14[13] = 'D';

    std::map<char, int> base14_to_digit;
    for(auto& [k, v] :  digit_to_base14){
        base14_to_digit[v] = k;
    }

    int idx1 = a1.size() - 1;
    int idx2 = a2.size() - 1;
    int carry = 0;
    int digit_sum = 0;
    std::string res("");
    while(idx1 >= 0 && idx2 >= 0){
        digit_sum = base14_to_digit[a1[idx1]] + base14_to_digit[a2[idx2]] + carry;
        res.insert(res.begin(), digit_to_base14[digit_sum % 14]);
        if(digit_sum > 13){
            carry = 1;
        }
        else{
            carry = 0;
        }

        idx1--;
        idx2--;
    }

    while(idx1 >= 0){
        digit_sum = base14_to_digit[a1[idx1]] + carry;
        res.insert(res.begin(), digit_to_base14[digit_sum % 14]);
        if(digit_sum > 13){
            carry = 1;
        }
        else{
            carry = 0;
        }

        idx1--;
    }

    while(idx2 >= 0){
        digit_sum = base14_to_digit[a2[idx2]] + carry;
        res.insert(res.begin(), digit_to_base14[digit_sum % 14]);
        if(digit_sum > 13){
            carry = 1;
        }
        else{
            carry = 0;
        }

        idx2--;
    }

    if(carry){
        res.insert(res.begin(), '1');
    }

    return res;
}
