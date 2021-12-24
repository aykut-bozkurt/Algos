#include <algorithm>

template<class Iter>
void merge(Iter start, Iter end, Iter mid){
    using val_type = typename Iter::value_type;

    int left_size = std::distance(start, mid) + 1;
    int right_size = std::distance(mid + 1, end) + 1;
    int tmp_size = left_size + right_size;

    val_type tmp[tmp_size];
    std::copy_n(start, tmp_size, tmp);

    int left_idx = 0;
    int right_idx = 0;
    int tmp_idx = 0;

    while(left_idx < left_size && right_idx < right_size){
        auto left_val = *(start + left_idx);
        auto right_val = *(mid + 1 + right_idx);

        if(left_val <= right_val){
            tmp[tmp_idx] = left_val;
            left_idx++;
        }
        else{
            tmp[tmp_idx] = right_val;
            right_idx++;
        }

        tmp_idx++;
    }

    while(left_idx < left_size){
        auto left_val = *(start + left_idx);
        tmp[tmp_idx] = left_val;
        left_idx++;
        tmp_idx++;
    }

    while(right_idx < right_size){
        auto right_val = *(mid + 1 + right_idx);
        tmp[tmp_idx] = right_val;
        right_idx++;
        tmp_idx++;
    }

    // copy back to real array
    for(std::size_t i = 0; i < tmp_size ; i++){
        *(start + i) = tmp[i];
    }
}

template<class Iter>
void merge_sort(Iter start, Iter end){
    if(start == end){
        return;
    }

    auto mid = start + (std::distance(start, end) / 2);

    merge_sort(start, mid);
    merge_sort(mid + 1, end);

    merge(start, end, mid);
}
