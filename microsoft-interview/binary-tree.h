#pragma once

struct BinaryTreeNode{
    BinaryTreeNode(int val) : val(val), left(nullptr), right(nullptr) {}

    int val;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
};

class BinaryTree{
  public:
    BinaryTree() = default;

    void insert(int val);

    bool search(int val);

    void remove(int val);

    int size();
  private:
    BinaryTreeNode* head;
    int node_count = 0;
};
