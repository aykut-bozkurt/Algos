#include "red-black-tree.h"
#include <algorithm>
#include <iostream>

RedBlackTreeNode* RedBlackTree::get_min(RedBlackTreeNode *cur) {
    if(cur->left){
        return get_min(cur->left);
    }

    return cur;
}

bool RedBlackTree::is_ll(RedBlackTreeNode* grand_parent) {
    auto uncle = grand_parent->right;
    auto child = grand_parent->left;

    // it should be black uncle and red parent
    if(get_color(uncle) == RBTreeColor::Red || get_color(child) == RBTreeColor::Black){
        return false;
    }

    if(child == nullptr){
        return false;
    }

    auto grand_child = child->left;

    if(grand_child == nullptr){
        return false;
    }

    // it should be red child
    if(get_color(grand_child) == RBTreeColor::Black){
        return false;
    }

    return true;
}

bool RedBlackTree::is_lr(RedBlackTreeNode* parent) {
    if(parent == nullptr){
        return false;
    }

    auto grand_parent = parent->parent;

    if(grand_parent == nullptr){
        return false;
    }

    auto uncle = grand_parent->right;

    // it should be black uncle and red parent
    if(get_color(uncle) == RBTreeColor::Red || get_color(parent) == RBTreeColor::Black){
        return false;
    }

    auto child = parent->right;

    if(child == nullptr){
        return false;
    }

    // it should be red child
    if(get_color(child) == RBTreeColor::Black){
        return false;
    }

    return true;
}

bool RedBlackTree::is_rl(RedBlackTreeNode* parent) {
    if(parent == nullptr){
        return false;
    }

    auto grand_parent = parent->parent;

    if(grand_parent == nullptr){
        return false;
    }

    auto uncle = grand_parent->left;

    // it should be black uncle and red parent
    if(get_color(uncle) == RBTreeColor::Red || get_color(parent) == RBTreeColor::Black){
        return false;
    }

    auto child = parent->left;

    if(child == nullptr){
        return false;
    }

    // it should be red child
    if(get_color(child) == RBTreeColor::Black){
        return false;
    }

    return true;
}

bool RedBlackTree::is_rr(RedBlackTreeNode* grand_parent) {
    auto uncle = grand_parent->left;
    auto child = grand_parent->right;

    // it should be black uncle and red parent
    if(get_color(uncle) == RBTreeColor::Red || get_color(child) == RBTreeColor::Black){
        return false;
    }

    if(child == nullptr){
        return false;
    }

    auto grand_child = child->right;

    if(grand_child == nullptr){
        return false;
    }

    // it should be red child
    if(get_color(grand_child) == RBTreeColor::Black){
        return false;
    }

    return true;
}

bool RedBlackTree::is_recolor(RedBlackTreeNode* child) {
    auto parent = child->parent;
    auto uncle = get_uncle(child);

    if(get_color(parent) == RBTreeColor::Red &&
        get_color(uncle) == RBTreeColor::Red &&
        get_color(child) == RBTreeColor::Red){
        return true;
    }
    else{
        return false;
    }
}

RedBlackTreeNode* RedBlackTree::get_sibling(RedBlackTreeNode* child) {
    auto parent = child->parent;
    if(parent->left == child){
        return parent->right;
    }
    else{
        return parent->left;
    }
}

RedBlackTreeNode* RedBlackTree::get_uncle(RedBlackTreeNode* child) {
    auto parent = child->parent;
    auto grandparent = parent->parent;
    if(grandparent){
        if(grandparent->left == parent){
            return grandparent->right;
        }
        else{
            return grandparent->left;
        }
    }

    return nullptr;
}

RBTreeColor RedBlackTree::get_color(RedBlackTreeNode *cur){
    if(cur){
        return cur->rb_tree_color;
    }

    return RBTreeColor::Black;
}

RedBlackTreeNode* RedBlackTree::left_rotate(RedBlackTreeNode* cur) {
    auto x = cur->right;
    auto y = x->left;

    cur->right = y;
    x->left = cur;

    x->parent = cur->parent;
    cur->parent = x;
    if(y){
        y->parent = cur;
    }

    return x;
}

RedBlackTreeNode* RedBlackTree::right_rotate(RedBlackTreeNode* cur) {
    auto x = cur->left;
    auto y = x->right;

    cur->left = y;
    x->right = cur;

    x->parent = cur->parent;
    cur->parent = x;
    if(y){
        y->parent = cur;
    }

    return x;
}

RedBlackTreeNode* RedBlackTree::insert(RedBlackTreeNode *cur, int val) {
    if(head == nullptr){
        // if we insert into root, recolor the node to black
        auto node = new RedBlackTreeNode(val);
        node->rb_tree_color = RBTreeColor::Black;
        return node;
    }
    else if(cur == nullptr){
        // we found insertion point, insert default red node
        return new RedBlackTreeNode(val);
    }
    else if(val <= cur->val){
        cur->left = insert(cur->left, val);
        cur->left->parent = cur;

        if(cur->left->recolored){
            if(cur == head){
                cur->left->recolored = false;
            }
            else{
                if(cur->left->rb_tree_color == RBTreeColor::Black){
                    cur->rb_tree_color = RBTreeColor::Red;
                }
                else{
                    cur->rb_tree_color = RBTreeColor::Black;
                }

                cur->left->recolored = false;
                cur->recolored = true;
            }

            return cur;
        }
        else if(is_recolor(cur->left)){
            // recolor
            auto uncle = get_uncle(cur->left);

            cur->rb_tree_color = RBTreeColor::Black;
            uncle->rb_tree_color = RBTreeColor::Black;
            cur->recolored = true;

            return cur;
        }
        else if(is_ll(cur)){
            auto node = right_rotate(cur);
            std::swap(node->rb_tree_color, cur->rb_tree_color);
            return node;
        }
        else if(is_rl(cur)){
            return right_rotate(cur);
        }
        else{
            return cur;
        }
    }
    else{
        cur->right = insert(cur->right, val);
        cur->right->parent = cur;

        if(cur->right->recolored){
            if(cur == head){
                cur->right->recolored = false;
            }
            else{
                if(cur->right->rb_tree_color == RBTreeColor::Black){
                    cur->rb_tree_color = RBTreeColor::Red;
                }
                else{
                    cur->rb_tree_color = RBTreeColor::Black;
                }

                cur->right->recolored = false;
                cur->recolored = true;
            }

            return cur;
        }
        else if(is_recolor(cur->right)){
            // recolor
            auto uncle = get_uncle(cur->right);

            cur->rb_tree_color = RBTreeColor::Black;
            uncle->rb_tree_color = RBTreeColor::Black;
            cur->recolored = true;

            return cur;
        }
        else if(is_rr(cur)){
            auto node = left_rotate(cur);
            std::swap(node->rb_tree_color, cur->rb_tree_color);
            return node;
        }
        else if(is_lr(cur)){
            return left_rotate(cur);
        }
        else{
            return cur;
        }
    }
}

void RedBlackTree::insert(int val) {
    head = insert(head, val);
}

RedBlackTreeNode* RedBlackTree::remove(RedBlackTreeNode* cur, int val) {
    /*if(cur == nullptr){
        return nullptr;
    }
    else if(val == cur->val){
        if(cur->left == nullptr && cur->right == nullptr){
            // no child
            return nullptr;
        }
        else if(cur->left == nullptr){
            // 1 child(right)
            return cur->right;
        }
        else if(cur->right == nullptr){
            // 1 child(left)
            return cur->left;
        }
        else{
            // 2 childs
            auto right_min = get_min(cur->right);
            cur->val = val;
            cur->right = remove(cur->right, val);

            return cur;
        }
    }
    else if(val < cur->val){
        cur->left = remove(cur->left, val);
        return cur;
    }
    else{
        cur->right = remove(cur->right, val);
        return cur;
    }*/
}

void RedBlackTree::remove(int val) {
    head = remove(head, val);
}

bool RedBlackTree::search(int val) {
    RedBlackTreeNode* cur = head;

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

void RedBlackTree::preorder(RedBlackTreeNode *cur) {
    if(cur == nullptr){
        return;
    }

    std::cout << cur->val << " ";
    preorder(cur->left);
    preorder(cur->right);
}

void RedBlackTree::preorder() {
    preorder(head);
    std::cout << std::endl;
}
