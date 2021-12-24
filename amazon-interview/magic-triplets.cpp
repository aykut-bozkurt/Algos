#include "magic-triplets.h"

#include <iostream>
#include <algorithm>

void magic_triplets(const std::vector<int>& numbers, int cur_idx, std::set<std::string>& unique_triplets, std::vector<int>& triplets, int sum){
    // O(2^n)
    if(triplets.size() == 3){
        if(sum == 0){
            std::vector<int> temp(triplets.begin(), triplets.end());
            std::sort(temp.begin(), temp.end());
            unique_triplets.insert(std::to_string(temp[0]) + "," + std::to_string(temp[1]) + "," + std::to_string(temp[2]));
        }

       return;
    }
    else if(cur_idx == numbers.size()){
        return;
    }

    // including cur
    triplets.push_back(numbers[cur_idx]);
    magic_triplets(numbers, cur_idx + 1, unique_triplets, triplets, sum + numbers[cur_idx]);
    triplets.erase(triplets.end() - 1);

    // nonincluding cur
    magic_triplets(numbers, cur_idx + 1, unique_triplets, triplets, sum);
}

void magic_triplets(std::vector<int>& numbers, std::set<std::string>& unique_triplets){
    // O(nlogn + n^2)
    std::sort(numbers.begin(), numbers.end());

    for(int i = 0; i < numbers.size(); i++){
        int required_sum = -numbers[i];
        int left = i + 1;
        int right = numbers.size() - 1;

        while(left < right){
            int cur_sum = numbers[left] + numbers[right];

            if(required_sum == cur_sum){
                unique_triplets.insert(std::to_string(numbers[i]) + "," + std::to_string(numbers[left]) + "," + std::to_string(numbers[right]));

                left++; // right-- will also works here
            }
            else if(cur_sum < required_sum){
                left++;
            }
            else{
                right--;
            }
        }
    }
}
