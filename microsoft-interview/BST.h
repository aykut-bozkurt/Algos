#pragma once

struct BSTNode{
    BSTNode(int val) : val(val), left(nullptr), right(nullptr){}
    int val;
    BSTNode* left;
    BSTNode* right;
};

class BST{
  public:
    BST() = default;

    void insert(int val);
    void remove(int val);
    bool search(int val);

    void preorder();
  private:
    BSTNode* head = nullptr;

    BSTNode* insert(BSTNode* cur, int val);
    BSTNode* remove(BSTNode* cur, int val);

    BSTNode* get_min(BSTNode* cur);

    void preorder(BSTNode* cur);
};