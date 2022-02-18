#pragma once

struct FibonacciHeapNode{
    FibonacciHeapNode(int val) : val(val), degree(0), marked(false), left(this), right(this), parent(nullptr) {}

    int val;
    int degree;
    bool marked;
    FibonacciHeapNode* child;
    FibonacciHeapNode* parent;
    FibonacciHeapNode* left;
    FibonacciHeapNode* right;
};

class FibonacciHeap{
  public:
    FibonacciHeap() = default;
    FibonacciHeap(FibonacciHeapNode* start){
        head = start;
        tail = start->left;
        min_node = start;
    }

    FibonacciHeapNode* insert(int val);
    void merge(FibonacciHeap* h2);
    int get_min();
    void decrease(FibonacciHeapNode* node, int val);
    void remove(FibonacciHeapNode* node);
    void extract_min();
  private:
    FibonacciHeapNode* min_node = nullptr;
    FibonacciHeapNode* head = nullptr;
    FibonacciHeapNode* tail = nullptr;

    void consolidate();
    void cut_link(FibonacciHeapNode* node);
    void unite(FibonacciHeapNode* node1, FibonacciHeapNode* node2);
};
