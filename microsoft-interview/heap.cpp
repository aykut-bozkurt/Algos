#include "heap.h"
#include <cmath>
#include <iostream>

Heap::Heap() {}

int Heap::size() {
    return vec.size();
}

void Heap::push(int val) {
    vec.push_back(val);

    int cur_idx = vec.size() - 1;
    int parent_idx = std::ceil(1.0f * cur_idx / 2) - 1;

    while(parent_idx >= 0){
        if(vec[parent_idx] > vec[cur_idx]){
            std::swap(vec[parent_idx], vec[cur_idx]);
            cur_idx = parent_idx;
            parent_idx = std::ceil(1.0f * cur_idx / 2) - 1;
        }
        else{
            return;
        }
    }
}

int& Heap::top() {
    return vec[0];
}

void Heap::pop() {
    std::swap(vec[0], vec[vec.size()-1]);
    vec.pop_back();

    int cur_idx = 0;
    int left_child_idx;
    int right_child_idx;

    while(cur_idx < vec.size()){
        left_child_idx = 2 * cur_idx + 1;
        right_child_idx = 2 * cur_idx + 2;

        if(left_child_idx < vec.size() && right_child_idx < vec.size()){
            if(vec[cur_idx] > vec[left_child_idx] || vec[cur_idx] > vec[right_child_idx]){
                if(vec[right_child_idx] <= vec[left_child_idx]){
                    std::swap(vec[cur_idx], vec[right_child_idx]);
                    cur_idx = right_child_idx;
                }
                else{
                    std::swap(vec[cur_idx], vec[left_child_idx]);
                    cur_idx = left_child_idx;
                }
            }
            else{
                break;
            }
        }
        else if(left_child_idx < vec.size()){
            if(vec[cur_idx] > vec[left_child_idx]){
                if(vec[right_child_idx] <= vec[left_child_idx]){
                    std::swap(vec[cur_idx], vec[right_child_idx]);
                    cur_idx = right_child_idx;
                }
                else{
                    break;
                }
            }
            else{
                break;
            }
        }
        else if(right_child_idx < vec.size()){
            if(vec[cur_idx] > vec[right_child_idx]){
                if(vec[left_child_idx] <= vec[right_child_idx]){
                    std::swap(vec[cur_idx], vec[left_child_idx]);
                    cur_idx = left_child_idx;
                }
                else{
                    break;
                }
            }
            else{
                break;
            }
        }
        else{
            break;
        }
    }
}

void Heap::print() {
    if(vec.size() > 0){
        for(auto num : vec){
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
    else{
        std::cout << "Heap is empty!" << std::endl;
    }
}