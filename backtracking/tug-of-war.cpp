#include "tug-of-war.h"

#include <cinttypes>
#include <iostream>

static void print_sets(const std::vector<int> sol, const std::vector<int> a){
    std::cout << "Set1: ";
    for(std::size_t i = 0; i < sol.size(); i++){
        if(sol[i] == 1){
            std::cout << a[i] << " ";
        }
    }
    std::cout << std::endl;

    std::cout << "Set2: ";
    for(std::size_t i = 0; i < sol.size(); i++){
        if(sol[i] == 2){
            std::cout << a[i] << " ";
        }
    }
    std::cout << std::endl;
}

static inline bool is_safe(const std::vector<int>& sol, const int cur_size1, const int cur_size2){
    // size total should not exceed total element
    if(cur_size1 + cur_size2 >= sol.size()){
        return false;
    }

    // already assigned
    if(sol[cur_size1 + cur_size2] != 0){
        return false;
    }

    return true;
}

static void tug_of_war(const std::vector<int>& a, std::vector<int>& cur_sol, int& cur_score, std::vector<int>& min_sol, int& min_score, int cur_size1, int cur_size2, const int size1, const int size2){
    if(cur_size1 == size1 && cur_size2 == size2){
        if(std::abs(cur_score) < min_score){
            min_score = std::abs(cur_score);
            min_sol = cur_sol;
        }
    }
    else{
        for(std::size_t set = 1; set <= 2; set++){
            if(is_safe(cur_sol, cur_size1, cur_size2)){
                cur_sol[cur_size1+cur_size2] = set;
                if(set == 1){
                    cur_score += a[cur_size1+cur_size2];
                    cur_size1++;
                }
                else{
                    cur_score -= a[cur_size1+cur_size2];
                    cur_size2++;
                }

                tug_of_war(a, cur_sol, cur_score, min_sol, min_score, cur_size1, cur_size2, size1, size2);

                if(set == 1){
                    cur_size1--;
                    cur_score -= a[cur_size1+cur_size2];
                }
                else{
                    cur_size2--;
                    cur_score += a[cur_size1+cur_size2];
                }
                cur_sol[cur_size1+cur_size2] = 0;
            }
        }
    }
}

void tug_of_war(const std::vector<int>& a){
    int cur_score = 0;
    int min_score = INT32_MAX;

    std::vector<int> cur_sol(a.size(), 0);
    std::vector<int> min_sol(a.size(), 0);

    std::size_t set1_size;
    std::size_t set2_size;

    if(a.size() % 2 == 0){
        set1_size = a.size()/2;
        set2_size = a.size()/2;
    }
    else{
        set1_size = (a.size()+1)/2;
        set2_size = (a.size()-1)/2;
    }

    tug_of_war(a, cur_sol, cur_score, min_sol, min_score, 0, 0, set1_size, set2_size);
    print_sets(min_sol, a);
}
