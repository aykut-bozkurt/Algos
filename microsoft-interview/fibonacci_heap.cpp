#include "fibonacci_heap.h"
#include <unordered_map>

// O(1)
FibonacciHeapNode* FibonacciHeap::insert(int val) {
    FibonacciHeapNode* node = new FibonacciHeapNode(val);

    if(head == nullptr){
        head = node;
        tail = node;
        min_node = node;
    }
    else{
        // update links, put the node into head
        if(head->left){
            head->left->right = node;
        }
        node->left = head->left;
        node->right = head;
        head->left = node;

        if(val < head->val){
            // update min node if val is the smallest
            min_node = node;
        }
        head = node;
    }

    return node;
}

// O(1)
void FibonacciHeap::merge(FibonacciHeap* h2) {
    if(this->head == nullptr){
        this->head = h2->head;
        this->tail = h2->tail;
        this->min_node = h2->min_node;
        return;
    }

    auto node = h2->head;
    auto tail2 = h2->tail;

    // middle connection
    node->left = tail;
    tail->right = node;

    // merged head and tail connections
    head->left = tail2;
    tail2->right = head;

    // change tail
    this->tail = tail2;

    // update min
    if(min_node == nullptr || min_node->val > h2->min_node->val){
        this->min_node = h2->min_node;
    }
}

// O(1)
int FibonacciHeap::get_min() {
    return min_node->val;
}

void FibonacciHeap::unite(FibonacciHeapNode* node1, FibonacciHeapNode* node2) {
    // put node2 under node1
    if(node2 == tail){
        tail = node2->left;
    }
    if(node2 == head){
        head = node2->right;
    }

    // remove node2 from root list
    node2->left->right = node2->right;
    node2->right->left = node2->left;
    node2->left = node2;
    node2->right = node2;

    // connect node 2 to parent and siblings
    auto child = node1->child;
    if(child){
        node2->left = child->left;
        node2->right = child;

        child->left->right = node2;
        child->left = node2;
    }
    node1->child = node2;
    node2->parent = node1;

    node1->degree++;
}

void FibonacciHeap::consolidate() {
    std::unordered_map<int,FibonacciHeapNode*> degree_to_trees;
    std::unordered_map<int,FibonacciHeapNode*>::iterator it;
    FibonacciHeapNode* tree;

    auto cur = head;
    while(cur != tail){
        it = degree_to_trees.find(cur->degree);

        if(it != degree_to_trees.end()){
            tree = it->second;
            degree_to_trees.erase(it);

            if(cur->val <= tree->val){
                // put tree under cur
                unite(cur, tree);
            }
            else{
                // put cur under tree
                unite(tree, cur);
                cur = tree;
            }
        }
        else{
            degree_to_trees.insert({cur->degree, cur});
            cur = cur->right;
        }
    }

    if(degree_to_trees.size() > 0){
        it = degree_to_trees.find(cur->degree);

        if(it != degree_to_trees.end()){
            tree = it->second;
            degree_to_trees.erase(it);

            if(cur->val <= tree->val){
                // put tree under cur
                unite(cur, tree);
            }
            else{
                // put cur under tree
                unite(tree, cur);
                cur = tree;
            }
        }
        else{
            degree_to_trees.insert({cur->degree, cur});
            cur = cur->right;
        }
    }
}

void FibonacciHeap::cut_link(FibonacciHeapNode* node) {
    // cut the link to parent
    node->parent = nullptr;

    // cut links to left and right siblings
    if(node->left){
        node->left->right = node->right;
    }
    if(node->right){
        node->right->left = node->left;
    }
    node->left = node;
    node->right = node;
}

// O(1)
void FibonacciHeap::decrease(FibonacciHeapNode* node, int val) {
    node->val = val;
    auto parent = node->parent;

    if(parent){
        // heap property is violated
        if(val < parent->val){
            if(parent->marked){
                // cut until parent is not marked
                do{
                    parent->marked = false;

                    // cut link to parent and siblings
                    cut_link(node);

                    // make it new heap and merge into rootlist
                    node->marked = false;
                    FibonacciHeap h2(node);
                    merge(&h2);

                    // move to parent
                    parent = parent->parent;
                } while(parent && parent->marked);
            }

            // mark parent if it is not a root node
            if(parent->parent){
                parent->marked = true;
            }
        }
    }
    else{
        if(val < min_node->val){
            min_node = node;
        }
    }
}

// O(logn)
void FibonacciHeap::extract_min() {
    auto child = min_node->child;

    // delete min
    if(min_node == head && head == tail){
        head = nullptr;
        tail = nullptr;
    }
    else if(min_node == head){
        head = head->right;
        head->left = tail;
        tail->right = head;
    }
    else if(min_node == tail){
        tail = tail->left;
        tail->right = head;
        head->left = tail;
    }
    else{
        min_node->left->right = min_node->right;
        min_node->right->left = min_node->left;
    }
    delete min_node;
    min_node = nullptr;

    // merge childs of deleted node
    if(child){
        child->parent = nullptr;
        FibonacciHeap h2(child);
        merge(&h2);
    }

    // update the min
    if(head){
        min_node = head;
        auto cur = head->right;
        while(cur != head){
            if(cur->val < min_node->val){
                min_node = cur;
            }

            cur = cur->right;
        }

        // consolidate
        consolidate();
    }
}

// O(logn)
void FibonacciHeap::remove(FibonacciHeapNode* node) {
    decrease(node, INT32_MIN);
    extract_min();
}
