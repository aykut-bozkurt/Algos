#pragma once

#include <vector>

// 1. brute force solution: traverse vector for the range. update = O(1), query = O(n) (useful if query is less)
// 2. array solution: store cumulative sums in array. update = O(n) , query = O(1) (useful if update is less)
// 3. segment tree solution: store binary intervals in segment tree. update = O(logn), query = O(logn) (optimal for both)

class SegmentTree{
  public:
    SegmentTree(const std::vector<int>& vec);

    int query(int l, int r);
    void update(int vec_idx, int val);
  private:
    std::vector<int> sums; // complete binary tree, which stores half interval sums in each node
    std::vector<int> vec;

    int query(const int l, const int r, int cur_l, int cur_r, int idx);
    void update(const int vec_idx, int cur_l, int cur_r, int idx, const int diff);

    void create_segment_tree(int l, int r, int idx);
};
