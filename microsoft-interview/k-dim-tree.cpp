#include "k-dim-tree.h"
#include <iostream>

KDimTreeNode* KDimTree::get_min(KDimTreeNode* cur, int dim) {
    if(cur == nullptr){
        return nullptr;
    }

    auto node1 = get_min(cur->left, dim);
    auto node2 = get_min(cur->right, dim);

    KDimTreeNode* min_node = cur;
    int min = cur->point.point[dim];
    if(node1){
        min_node = (node1->point.point[dim] <= min_node->point.point[dim]) ? node1 : min_node;
    }
    if(node2){
        min_node = (node2->point.point[dim] <= min_node->point.point[dim]) ? node2 : min_node;
    }

    return min_node;
}

KDimTreeNode* KDimTree::insert(KDimTreeNode* cur, const KDimPoint<2>& point, int depth) {
    if(cur == nullptr){
        return new KDimTreeNode(point);
    }

    int dim = depth % 2;

    if(point.point[dim] < cur->point.point[dim]){
        cur->left = insert(cur->left, point, depth + 1);
    }
    else{
        cur->right = insert(cur->right, point, depth + 1);
    }

    return cur;
}

void KDimTree::insert(const KDimPoint<2>& point) {
    head = insert(head, point, 0);
}

KDimTreeNode* KDimTree::remove(KDimTreeNode* cur, const KDimPoint<2>& point, int depth) {
    if(cur == nullptr){
        return nullptr;
    }

    int dim = depth % 2;

    if(point.point == cur->point.point){
        // find min of the current dimension and copy value to current node and recursively remove it
        if(cur->left && cur->right){
            auto min_node = get_min(cur->right, dim);
            cur->point = min_node->point;

            cur->right = remove(cur->right, min_node->point, depth + 1);
        }
        else if(cur->left){
            auto min_node = get_min(cur->left, dim);
            cur->point = min_node->point;

            cur = remove(cur->left, min_node->point, depth + 1);
        }
        else if(cur->right){
            auto min_node = get_min(cur->right, dim);
            cur->point = min_node->point;

            cur = remove(cur->right, min_node->point, depth + 1);
        }
        else{
            return nullptr;
        }
    }
    else if(point.point[dim] < cur->point.point[dim]){
        cur->left = remove(cur->left, point, depth + 1);
    }
    else{
        cur->right = remove(cur->right, point, depth + 1);
    }

    return cur;
}

void KDimTree::remove(const KDimPoint<2>& point) {
    head = remove(head, point, 0);
}

bool KDimTree::search(const KDimPoint<2>& point) {
    auto cur = head;

    int depth = 0;
    while(cur){
        int dim = depth % 2;

        if(point.point == cur->point.point){
            return true;
        }
        else if(point.point[dim] < cur->point.point[dim]){
            cur = cur->left;
        }
        else{
            cur = cur->right;
        }

        depth++;
    }

    return false;
}

void KDimTree::preorder(KDimTreeNode *cur) {
    if(cur == nullptr){
        return;
    }

    std::cout << "(" << cur->point.point[0] << ", " << cur->point.point[1] << ")" << " ";
    preorder(cur->left);
    preorder(cur->right);

    return;
}

void KDimTree::preorder() {
    preorder(head);
    std::cout << std::endl;
}
