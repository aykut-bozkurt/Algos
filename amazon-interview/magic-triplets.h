#pragma once

#include <vector>
#include <set>
#include <string>

void magic_triplets(const std::vector<int>& numbers, int cur_idx, std::set<std::string>& unique_triplets, std::vector<int>& triplets, int sum);

void magic_triplets(std::vector<int>& numbers, std::set<std::string>& unique_triplets);
