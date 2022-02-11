#include "AVL.h"
#include <algorithm>
#include <iostream>

AVLNode* AVL::left_rotation(AVLNode *cur) {
    // update links and heights and return head of rotated sub tree
    auto x = cur->right;
    auto y = cur->right->left;

    x->left = cur;
    cur->right = y;

    cur->height = 1 + std::max(height(cur->left), height(cur->right));
    x->height = 1 + std::max(height(x->left), height(x->right));

    return x;
}

AVLNode* AVL::right_rotation(AVLNode *cur) {
    // update links and heights and return head of rotated sub tree
    auto x = cur->left;
    auto y = x->right;

    x->right = cur;
    cur->left = y;

    cur->height = 1 + std::max(height(cur->left), height(cur->right));
    x->height = 1 + std::max(height(x->left), height(x->right));

    return x;
}

int AVL::balance_factor(AVLNode* cur) {
    int factor = 0;

    if(cur->left){
        factor += cur->left->height;
    }

    if(cur->right){
        factor -= cur->right->height;
    }

    return factor;
}

int AVL::height(AVLNode *cur) {
    if(cur){
        return cur->height;
    }

    return -1;
}

AVLNode* AVL::insert(AVLNode* cur, int val) {
    if(cur == nullptr){
        return new AVLNode{val, 0, nullptr, nullptr};
    }
    else if(val <= cur->val){
        cur->left = insert(cur->left, val);
    }
    else{
        cur->right = insert(cur->right, val);
    }

    cur->height = 1 + std::max(height(cur->left), height(cur->right));

    int factor = balance_factor(cur);

    // left-left case
    if(factor > 1 && val <= cur->left->val){
        return right_rotation(cur);
    }
    // right-right case
    else if(factor < -1 && val > cur->right->val){
        return left_rotation(cur);
    }
    // left-right case
    else if(factor > 1 && val > cur->left->val){
        cur->left = left_rotation(cur->left);
        return right_rotation(cur);
    }
    // right-left case
    else if(factor < -1 && val <= cur->right->val){
        cur->right = right_rotation(cur->right);
        return left_rotation(cur);
    }
    // no rotation
    else{
        return cur;
    }
}

void AVL::insert(int val) {
    head = insert(head, val);
}

AVLNode* AVL::get_min(AVLNode *cur) {
    if(cur->left){
        return get_min(cur->left);
    }

    return cur;
}

AVLNode* AVL::remove(AVLNode *cur, int val) {
    if(cur == nullptr){
        return cur;
    }
    else if(val < cur->val){
        cur->left = remove(cur->left, val);
    }
    else if(val > cur->val){
        cur->right = remove(cur->right, val);
    }
    else{
        // 2 childs
        if(cur->left && cur->right){
            auto node = get_min(cur->right);
            cur->val = node->val;
            cur->right = remove(cur->right, node->val);
        }
        // only left child
        else if(cur->left){
            cur = cur->left;
        }
        // only right child
        else if(cur->right){
            cur = cur->right;
        }
        // no child
        else{
            cur = nullptr;
        }
    }

    if(cur == nullptr){
        return nullptr;
    }

    cur->height = 1 + std::max(height(cur->left), height(cur->right));

    int factor = balance_factor(cur);

    // left-left case
    if(factor > 1 && balance_factor(cur->left) >= 0){
        return right_rotation(cur);
    }
    // right-right case
    else if(factor < -1 && balance_factor(cur->right) <= 0){
        return left_rotation(cur);
    }
    // left-right case
    else if(factor > 1 && balance_factor(cur->left) < 0){
        cur->left = left_rotation(cur->left);
        return right_rotation(cur);
    }
    // right-left case
    else if(factor < -1 && balance_factor(cur->right) > 0){
        cur->right = right_rotation(cur->right);
        return left_rotation(cur);
    }
    // no rotation
    else{
        return cur;
    }
}

void AVL::remove(int val) {
    head = remove(head, val);
}

bool AVL::search(int val) {
    AVLNode* cur = head;

    while(cur != nullptr){
        if(cur->val == val){
            return true;
        }
        else if(val < cur->val){
            cur = cur->left;
        }
        else{
            cur = cur->right;
        }
    }

    return false;
}

void AVL::preorder() {
    preorder(head);
    std::cout << std::endl;
}

void AVL::preorder(AVLNode* cur) {
    if(cur == nullptr){
        return;
    }

    std::cout << cur->val << " ";
    preorder(cur->left);
    preorder(cur->right);
}