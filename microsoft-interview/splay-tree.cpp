#include "splay-tree.h"
#include <algorithm>
#include <iostream>

SplayTreeNode* SplayTree::zig(SplayTreeNode *cur) {
    // right rotate cur
    auto x = cur->left;
    auto y = x->right;

    cur->left = y;
    x->right = cur;

    return x;
}

SplayTreeNode* SplayTree::zag(SplayTreeNode *cur) {
    // left rotate cur
    auto x = cur->right;
    auto y = x->left;

    cur->right = y;
    x->left = cur;

    return x;
}

SplayTreeNode* SplayTree::insert(SplayTreeNode *cur, int val) {
    if(cur == nullptr){
        return new SplayTreeNode(val);
    }

    if(val <= cur->val){
        cur->left = insert(cur->left, val);
    }
    else{
        cur->right = insert(cur->right, val);
    }

    return cur;
}

void SplayTree::insert(int val) {
    head = insert(head, val);
    head = splay(head, val);
}

SplayTreeNode* SplayTree::get_min(SplayTreeNode *cur) {
    if(cur->left){
        return get_min(cur->left);
    }

    return cur;
}

SplayTreeNode* SplayTree::remove(SplayTreeNode *cur, int val) {
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

void SplayTree::remove(int val) {
    head = remove(head, val);
}

SplayTreeNode* SplayTree::splay(SplayTreeNode* cur, int val) {
    if(cur == nullptr){
        // not found
        return nullptr;
    }
    else if(cur == head && cur->val == val){
        // found at head
        return cur;
    }
    else if(cur == head && cur->left && val == cur->left->val){
        // found at head's left child
        return zig(cur);
    }
    else if(cur == head && cur->right && val == cur->right->val){
        // found at head's right child
        return zag(cur);
    }
    else if(val > cur->val){
        cur->right = splay(cur->right, val);

        if(cur->right && cur->right->val == val){
            return zag(cur);
        }
    }
    else if(val < cur->val){
        cur->left = splay(cur->left, val);

        if(cur->left && cur->left->val == val){
            return zig(cur);
        }
    }

    return cur;
}

bool SplayTree::search(int val) {
    head = splay(head, val);

    return head && head->val == val;
}

void SplayTree::preorder() {
    preorder(head);
    std::cout << std::endl;
}

void SplayTree::preorder(SplayTreeNode *cur) {
    if(cur == nullptr){
        return;
    }

    std::cout << cur->val << " ";
    preorder(cur->left);
    preorder(cur->right);
}
