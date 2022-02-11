#pragma once

struct AVLNode{
    int val;
    int height;
    AVLNode* left;
    AVLNode* right;
};

class AVL{
  public:
    AVL() = default;

    void insert(int val);
    void remove(int val);
    bool search(int val);

    void preorder();
  private:
    AVLNode* head = nullptr;

    AVLNode* insert(AVLNode* cur, int val);
    AVLNode* remove(AVLNode* cur, int val);

    int balance_factor(AVLNode* cur);
    int height(AVLNode* cur);

    AVLNode* left_rotation(AVLNode* cur);
    AVLNode* right_rotation(AVLNode* cur);

    AVLNode* get_min(AVLNode* cur);

    void preorder(AVLNode* cur);
};