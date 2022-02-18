#pragma once

struct BinomialHeapNode{
    BinomialHeapNode(int val) : val(val), degree(0) {
        child = nullptr;
        parent = nullptr;
        sibling = nullptr;
    }

    int val;
    int degree;
    BinomialHeapNode* child;
    BinomialHeapNode* parent;
    BinomialHeapNode* sibling;
};

class BinomialHeap{
  public:
    BinomialHeap() = default;

    BinomialHeapNode* insert(int val);
    void merge(BinomialHeap* h2);
    int get_min();
    void decrease(BinomialHeapNode* node, int val);
    void remove(BinomialHeapNode* node);
    void extract_min();
  private:
    BinomialHeapNode* head = nullptr;

    BinomialHeapNode* merge(BinomialHeapNode* node1, BinomialHeapNode* node2);
    BinomialHeapNode* reverse_child_roots(BinomialHeapNode* root);
    int get_degree(BinomialHeapNode* node);
    void consolidate();
};