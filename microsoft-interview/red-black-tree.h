#pragma once

//Properties
// 1. No adj red nodes,
// 2. External nodes are black,
// 3. All paths from root to external nodes have same number of black nodes,
// 4. Root node is black.

//Rules
// 1. insert node as red
// if it will be root, recolor it to black.
// else parent is black, no problem; otherwise check uncle's color.
// if uncle is red as well, recolor uncle and parent to black and recolor until root
// if uncle is black, do rotations for ll, lr, rr, and rl cases (rotate grandparent) and swap color accordingly

enum class RBTreeColor{
    Red = 0,
    Black = 1
};

struct RedBlackTreeNode{
    RedBlackTreeNode(int val) : val(val), recolored(false), parent(nullptr), rb_tree_color(RBTreeColor::Red), left(nullptr), right(nullptr){}

    int val;
    bool recolored;
    RBTreeColor rb_tree_color;
    RedBlackTreeNode* parent;
    RedBlackTreeNode* left;
    RedBlackTreeNode* right;
};

class RedBlackTree{
  public:
    RedBlackTree() = default;

    void insert(int val);
    void remove(int val);
    bool search(int val);

    void preorder();
  private:
    RedBlackTreeNode* head = nullptr;

    RedBlackTreeNode* insert(RedBlackTreeNode* cur, int val);
    RedBlackTreeNode* remove(RedBlackTreeNode* cur, int val);

    RedBlackTreeNode* get_min(RedBlackTreeNode* cur);

    void preorder(RedBlackTreeNode* cur);

    RedBlackTreeNode* get_uncle(RedBlackTreeNode* child);
    RedBlackTreeNode* get_sibling(RedBlackTreeNode* child);
    RBTreeColor get_color(RedBlackTreeNode* cur);

    RedBlackTreeNode* left_rotate(RedBlackTreeNode* cur);
    RedBlackTreeNode* right_rotate(RedBlackTreeNode* cur);

    bool is_ll(RedBlackTreeNode* grand_parent);
    bool is_lr(RedBlackTreeNode* parent);
    bool is_rr(RedBlackTreeNode* grand_parent);
    bool is_rl(RedBlackTreeNode* parent);
    bool is_recolor(RedBlackTreeNode* child);
};