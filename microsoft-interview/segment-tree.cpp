#include "segment-tree.h"
#include <algorithm>
#include <numeric>
#include <cmath>

SegmentTree::SegmentTree(const std::vector<int>& vec) : vec(vec) {
    int max_tree_height = std::ceil(std::log2(vec.size())) + 1;
    int max_tree_size = std::pow(2, max_tree_height) - 1;
    sums.resize(max_tree_size);

    create_segment_tree(0, vec.size()-1, 0);
}

void SegmentTree::create_segment_tree(int l, int r, int idx) {
    if(l == r){
        this->sums[idx] = vec[l];
        return;
    }

    int sum = 0;
    for(int i = l; i <= r; i++){
        sum += this->vec[i];
    }
    this->sums[idx] = sum;

    int mid = l + (r - l) / 2;
    create_segment_tree(l, mid, 2 * idx + 1);
    create_segment_tree(mid + 1, r, 2 * idx + 2);

    return;
}

// O(logn)
int SegmentTree::query(const int l, const int r, int cur_l, int cur_r, int idx) {
    if(cur_r < l || cur_l > r){
        // completely out of range
        return 0;
    }
    else if(cur_l >= l && cur_r <= r){
        // completely in the range
        return this->sums[idx];
    }

    // some parts are in range
    int mid = cur_l + (cur_r - cur_l) / 2;
    return query(l, r, cur_l, mid, 2 * idx + 1) + query(l, r, mid + 1, cur_r, 2 * idx + 2);
}

int SegmentTree::query(int l, int r) {
    return query(l, r, 0, vec.size() - 1, 0);
}

// O(logn)
void SegmentTree::update(const int vec_idx, int cur_l, int cur_r, int idx, const int diff) {
    if(cur_r < vec_idx || cur_l > vec_idx){
        // completely out of range
        return;
    }

    // some parts or all parts are in range
    sums[idx] += diff;

    if(cur_l == cur_r){
        return;
    }

    int mid = cur_l + (cur_r - cur_l) / 2;
    update(vec_idx, cur_l, mid, 2 * idx + 1, diff);
    update(vec_idx, mid + 1, cur_r, 2 * idx + 2, diff);

    return;
}

void SegmentTree::update(int vec_idx, int val) {
    int diff = val - this->vec[vec_idx];
    this->vec[vec_idx] = val;

    update(vec_idx, 0, vec.size() - 1, 0, diff);
}
