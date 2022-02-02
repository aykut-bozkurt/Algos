#include "binary-tree.h"

int BinaryTree::size() {
    return node_count;
}

void BinaryTree::insert(int val) {
    if(head == nullptr){
        head = new BinaryTreeNode(val);
        return;
    }
    BinaryTreeNode* cur = head;
    BinaryTreeNode* parent;
    while(cur != nullptr){
        parent = cur;

        // always go to bottom right; if right is null, then go to left if has left child
        if(cur->left == nullptr){
            cur = cur->left;
            if(cur == nullptr){
                parent->left = new BinaryTreeNode(val);
            }
        }
        else if(cur->right == nullptr){
            cur = cur->right;
            if(cur == nullptr){
                parent->right = new BinaryTreeNode(val);
            }
        }
        else{
            parent->left = new BinaryTreeNode(val);
            break;
        }
    }
}