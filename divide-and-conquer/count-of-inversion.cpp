#include "count-of-inversion.h"

static int merge(std::vector<int>& a, int start_idx, int mid_idx, int end_idx){
    int left_start = start_idx;
    int right_start = mid_idx+1;

    std::vector<int> tmp(end_idx-left_start+1);
    std::size_t tmp_idx = 0;

    int inversion_count = 0;

    while((left_start <= mid_idx) && (right_start <= end_idx)){
        if(a[left_start] <= a[right_start]){
            tmp[tmp_idx] = a[left_start];
            left_start++;
        }
        else{
            inversion_count += (mid_idx - left_start + 1);

            tmp[tmp_idx] = a[right_start];
            right_start++;
        }

        tmp_idx++;
    }

    while(left_start <= mid_idx){
        tmp[tmp_idx] = a[left_start];
        left_start++;
        tmp_idx++;
    }

    while(right_start <= end_idx){
        tmp[tmp_idx] = a[right_start];
        right_start++;
        tmp_idx++;
    }

    std::copy(tmp.begin(), tmp.end(), std::next(a.begin(), start_idx));

    return inversion_count;
}

static int merge_sort(std::vector<int>& a, int start_idx, int end_idx){
    if(start_idx == end_idx){
        return 0;
    }

    // divide
    int mid_idx = (start_idx + end_idx) / 2;

    // conquer
    int inversion_count = 0;
    inversion_count += merge_sort(a, start_idx, mid_idx);
    inversion_count += merge_sort(a, mid_idx + 1, end_idx);

    // combine
    inversion_count += merge(a, start_idx, mid_idx, end_idx);

    return inversion_count;
}

int inversion_count(std::vector<int>& a){
    return merge_sort(a, 0, a.size()-1);
}
