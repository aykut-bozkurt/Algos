#pragma once

#include <array>

template<int k>
struct KDimPoint{
    KDimPoint() = default;
    KDimPoint(std::array<int, k> arr) : point(arr){}
    std::array<int, k> point;
};

struct KDimTreeNode{
    KDimTreeNode(const KDimPoint<2>& point){
        this->point = point;
        this->left = nullptr;
        this->right = nullptr;
    }

    KDimPoint<2> point;
    KDimTreeNode* left;
    KDimTreeNode* right;
};

class KDimTree{
  public:
    KDimTree() = default;

    void insert(const KDimPoint<2>& point);
    void remove(const KDimPoint<2>& point);
    bool search(const KDimPoint<2>& point);

    void preorder();
  private:
    KDimTreeNode* head = nullptr;

    KDimTreeNode* get_min(KDimTreeNode* cur, int dim);

    KDimTreeNode* insert(KDimTreeNode* cur, const KDimPoint<2>& point, int depth);
    KDimTreeNode* remove(KDimTreeNode* cur, const KDimPoint<2>& point, int depth);

    void preorder(KDimTreeNode* cur);
};
