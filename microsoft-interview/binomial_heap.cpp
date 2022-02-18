#include "binomial_heap.h"
#include <climits>
#include <cmath>

// O(logn)
BinomialHeapNode* BinomialHeap::insert(int val) {
    // put node into root list
    BinomialHeapNode* node = new BinomialHeapNode(val);
    node->sibling = this->head;
    this->head = node;

    // then consolidate trees
    consolidate();

    return node;
}

int BinomialHeap::get_degree(BinomialHeapNode* node) {
    return (node) ? node->degree : -1;
}

void BinomialHeap::consolidate() {
    if(this->head == nullptr){
        return;
    }

    BinomialHeapNode* prev = nullptr;
    BinomialHeapNode* cur = this->head;
    BinomialHeapNode* next = cur->sibling;

    while(next){
        int cur_degree = get_degree(cur);
        int next_degree = get_degree(next);
        int next_next_degree = get_degree(next->sibling);

        if((cur_degree == next_degree) && (cur_degree != next_next_degree)){
            if(cur->val <= next->val){
                // next under cur
                cur->sibling = next->sibling;

                next->sibling = cur->child;
                next->parent = cur;
                cur->child = next;
                cur->degree++;

                // only next moves
                next = cur->sibling;
            }
            else{
                // cur under next
                if(prev){
                    prev->sibling = next;
                }

                cur->parent = next;
                cur->sibling = next->child;
                next->child = cur;
                next->degree++;

                // cur and next moves
                if(cur == head){
                    head = next;
                }
                cur = next;
                next = next->sibling;
            }
        }
        else{
            // all pointers move
            prev = cur;
            cur = cur->sibling;
            next = cur->sibling;
        }
    }
}

BinomialHeapNode* BinomialHeap::merge(BinomialHeapNode* node1, BinomialHeapNode *node2) {
    if(node1 == nullptr){
        return node2;
    }
    else if(node2 == nullptr){
        return node1;
    }

    if(node1->degree <= node2->degree){
        node1->sibling = merge(node1->sibling, node2);
        return node1;
    }
    else{
        node2->sibling = merge(node1, node2->sibling);
        return node2;
    }
}

// O(log(n+m))
void BinomialHeap::merge(BinomialHeap* h2) {
    // merge 2 binomial heap in non-decreasing binomial tree order using helper merger
    head = merge(this->head, h2->head);

    // consolidate tree after merge
    consolidate();
}

// O(logn) (if keep pointer O(1))
int BinomialHeap::get_min() {
    if(head == nullptr){
        return -1;
    }

    auto cur = head;

    int min = INT_MAX;
    while(cur != nullptr){
        if(cur->val < min){
            min = cur->val;
        }

        cur = cur->sibling;
    }

    return min;
}

// O(logn)
void BinomialHeap::decrease(BinomialHeapNode* node, int val) {
    if(node->val <= val){
        return;
    }

    auto parent = node->parent;

    while(parent && parent->val > val){
        // swap nodes until heap property is satisfied
        parent->child = node->child;
        node->parent = parent->parent;

        parent->parent = node;
        node->child = parent;

        node->sibling = parent->sibling;
        parent->sibling = node->sibling;

        // check next parent
        parent = node->parent;
    }

    node->val = val;
}

// O(logn)
void BinomialHeap::extract_min() {
    if(head == nullptr){
        return;
    }

    // find min
    BinomialHeapNode* min_prev = nullptr;
    BinomialHeapNode* min = nullptr;

    BinomialHeapNode* cur = head;
    BinomialHeapNode* prev = nullptr;
    int min_val = INT_MAX;
    while(cur){
        if(cur->val < min_val){
            min = cur;
            min_prev = prev;
            min_val = cur->val;
        }

        prev = cur;
        cur = cur->sibling;
    }

    // delete min
    if(min_prev){
        // set prev's sibling the next of min node
        min_prev->sibling = min->sibling;
    }
    else{
        // min_prev is null, so min node is head, so update head as next
        head = min->sibling;
    }

    // merge child trees of removed item which are siblings of the child
    BinomialHeap h2{};
    h2.head = min->child;
    min->child->parent = nullptr;
    h2.head = reverse_child_roots(h2.head);
    merge(&h2);
}

// O(logn)
void BinomialHeap::remove(BinomialHeapNode* node) {
    decrease(node, INT_MIN);
    extract_min();
}

BinomialHeapNode* BinomialHeap::reverse_child_roots(BinomialHeapNode* root) {
    BinomialHeapNode* cur = root;
    BinomialHeapNode* next = cur->sibling;
    cur->sibling = nullptr;

    while(next){
        auto tmp = next->sibling;
        next->sibling = cur;

        cur = next;
        next = tmp;
    }

    return cur;
}
