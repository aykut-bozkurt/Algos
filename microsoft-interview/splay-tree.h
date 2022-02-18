#pragma once

struct SplayTreeNode{
    SplayTreeNode(int val) : val(val), left(nullptr), right(nullptr){}
    int val;
    SplayTreeNode* left;
    SplayTreeNode* right;
};

class SplayTree{
  public:
    SplayTree() = default;

    void insert(int val);
    void remove(int val);
    bool search(int val);

    void preorder();
  private:
    SplayTreeNode* head = nullptr;

    SplayTreeNode* insert(SplayTreeNode* cur, int val);
    SplayTreeNode* remove(SplayTreeNode* cur, int val);
    SplayTreeNode* splay(SplayTreeNode* cur, int val);

    SplayTreeNode* zig(SplayTreeNode* cur);
    SplayTreeNode* zag(SplayTreeNode* cur);

    SplayTreeNode* get_min(SplayTreeNode* cur);

    void preorder(SplayTreeNode* cur);
};