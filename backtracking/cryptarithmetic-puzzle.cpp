#include "cryptarithmetic-puzzle.h"

#include <cinttypes>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

static void print_puzzle(const std::string& unique_chars, const std::map<int, char>& sol){
    for(auto& [digit, letter] : sol){
        std::cout << letter << "= " << digit << std::endl;
    }
}

static inline bool is_true_chiper(const std::string& s1, const std::string& s2, const std::string& s3, std::map<int, char>& sol, std::map<char, int>& sol_rev){
    std::ptrdiff_t cur1_idx = s1.size()-1;
    std::ptrdiff_t cur2_idx = s2.size()-1;
    std::ptrdiff_t res_idx = s3.size()-1;

    std::size_t digit1;
    std::size_t digit2;
    std::size_t carry = 0;
    std::size_t digit_res;

    while(cur1_idx >= 0 && cur2_idx >= 0){
        digit1 = sol_rev[s1[cur1_idx]];
        digit2 = sol_rev[s2[cur2_idx]];
        digit_res = digit1 + digit2 + carry;
        if(digit_res > 9){
            carry = 1;
        }
        else{
            carry = 0;
        }
        digit_res = digit_res % 10;
        if(sol.find(digit_res) == sol.end()){
            return false;
        }
        else{
            if(sol[digit_res] != s3[res_idx]){
                return false;
            }
        }

        cur1_idx--;
        cur2_idx--;
        res_idx--;
    }

    while(cur1_idx >= 0){
        digit1 = sol_rev[s1[cur1_idx]];
        digit_res = digit1 + carry;
        if(digit_res > 9){
            carry = 1;
        }
        else{
            carry = 0;
        }
        digit_res = digit_res % 10;
        if(sol.find(digit_res) == sol.end()){
            return false;
        }
        else{
            if(sol[digit_res] != s3[res_idx]){
                return false;
            }
        }

        cur1_idx--;
        res_idx--;
    }

    while(cur2_idx >= 0){
        digit2 = sol_rev[s2[cur2_idx]];
        digit_res = digit2 + carry;
        if(digit_res > 9){
            carry = 1;
        }
        else{
            carry = 0;
        }
        digit_res = digit_res % 10;
        if(sol.find(digit_res) == sol.end()){
            return false;
        }
        else{
            if(sol[digit_res] != s3[res_idx]){
                return false;
            }
        }

        cur2_idx--;
        res_idx--;
    }

    if(carry){
        if(sol.find(carry) == sol.end()){
            return false;
        }
        else{
            if(sol[carry] != s3[res_idx]){
                return false;
            }
        }
    }
    else{
        if(res_idx >= 0){
            return false;
        }
    }

    return true;
}

static inline bool is_safe(std::map<int, char>& sol, const int digit){
    return sol.find(digit) == sol.end();
}

static bool cryptarithmetic_puzzle(const std::string& s1, const std::string& s2, const std::string& s3, const std::string& unique_chars, std::map<int, char>& sol, std::map<char, int>& sol_rev, int total_solved){
    if(total_solved == unique_chars.size()){
        if(is_true_chiper(s1, s2, s3, sol, sol_rev)){
            return true;
        }
        else{
            return false;
        }
    }

    for(std::size_t digit = 0; digit <= 9; digit++){
        if(is_safe(sol, digit)){
            sol[digit] = unique_chars[total_solved];
            sol_rev[unique_chars[total_solved]] = digit;
            total_solved++;

            if(cryptarithmetic_puzzle(s1, s2, s3, unique_chars, sol, sol_rev, total_solved)){
                return true;
            }

            total_solved--;
            sol.erase(digit);
            sol_rev.erase(unique_chars[total_solved]);
        }
    }

    return false;
}

void cryptarithmetic_puzzle(const std::string& s1, const std::string& s2, const std::string& s3){
    std::string chars;
    std::set<char> unique_chars;
    for(const auto& c : s1 + s2 + s3){
        auto res = unique_chars.insert(c);
        if(res.second){
            chars.push_back(c);
        }
    }

    std::map<int, char> sol;
    std::map<char, int> sol_rev;

    if(cryptarithmetic_puzzle(s1, s2, s3, chars, sol, sol_rev, 0)){
        print_puzzle(chars, sol);
    }
    else{
        std::cout << "No solution exists!" << std::endl;
    }
}
