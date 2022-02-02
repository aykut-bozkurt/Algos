#include "doubly-list.h"
#include <iostream>

Node* DoublyList::push_back(int val) {
    if(tail == nullptr){
        head = new Node(val);
        tail = head;
    }
    else{
        Node* cur = head;
        Node* prev = nullptr;

        while(cur != nullptr){
            prev = cur;
            cur = cur->next;
        }

        prev->next = new Node(val);
        prev->next->prev = prev;

        tail = prev->next;
    }

    return tail;
}

Node* DoublyList::search(int val) {
    Node* cur = head;

    while(cur != nullptr){
        if(cur->val == val){
            return cur;
        }

        cur = cur->next;
    }

    return nullptr;
}

Node* DoublyList::erase(int val) {
    Node* cur = search(val);

    if(cur == nullptr){
        // not found
        return nullptr;
    }
    else if(cur == head){
        if(cur->next){
            // only head
            cur->next->prev = nullptr;
            head = cur->next;
        }
        else{
            // both head and tail
            head = nullptr;
            tail = nullptr;
        }
    }
    else if(cur == tail){
        // only tail
        cur->prev->next = nullptr;
        tail = cur->prev;
    }
    else{
        // middle
        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;
    }

    cur->next = nullptr;
    cur->prev = nullptr;
    return cur;
}

void DoublyList::print() {
    Node* cur = head;

    if(cur){
        std::cout << "null <=> ";
        while(cur != nullptr){
            std::cout << cur->val << " <=> ";

            cur = cur->next;
        }
        std::cout << "null" << std::endl;
    }
    else{
        std::cout << "Doubly list is empty!" << std::endl;
    }
}