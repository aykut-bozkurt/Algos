#include "BST.h"
#include <algorithm>
#include <iostream>

BSTNode* BST::get_min(BSTNode *cur) {
    if(cur->left){
        return get_min(cur->left);
    }

    return cur;
}

BSTNode* BST::insert(BSTNode *cur, int val) {
    if(cur == nullptr){
        return new BSTNode(val);
    }

    if(val <= cur->val){
        cur->left = insert(cur->left, val);
    }
    else{
        cur->right = insert(cur->right, val);
    }

    return cur;
}

void BST::insert(int val) {
    head = insert(head, val);
}

BSTNode* BST::remove(BSTNode *cur, int val) {
    if(cur == nullptr){
        return nullptr;
    }

    if(val == cur->val){
        // 2 childs
        if(cur->left && cur->right){
            auto node = get_min(cur->right);
            cur->val = node->val;
            cur->right = remove(cur->right, node->val);
        }
        // 1 child(left)
        else if(cur->left){
            cur = cur->left;
        }
        // 1 child(right)
        else if(cur->right){
            cur = cur->right;
        }
        // no child
        else{
            cur = nullptr;
        }
    }
    else if(val < cur->val){
        cur->left = remove(cur->left, val);
    }
    else{
        cur->right = remove(cur->right, val);
    }

    return cur;
}

void BST::remove(int val) {
    head = remove(head, val);
}

bool BST::search(int val) {
    BSTNode* cur = head;

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

void BST::preorder() {
    preorder(head);
    std::cout << std::endl;
}

void BST::preorder(BSTNode *cur) {
    if(cur == nullptr){
        return;
    }

    std::cout << cur->val << " ";
    preorder(cur->left);
    preorder(cur->right);
}
