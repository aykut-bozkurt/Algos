#pragma once

struct Node{
    Node(int val) : val(val), next(nullptr), prev(nullptr){}

    int val;
    Node* next;
    Node* prev;
};

class DoublyList{
  public:
    DoublyList() = default;

    Node* push_back(int val);

    Node* erase(int val);

    Node* search(int val);

    void print();

  private:
    Node* head = nullptr;
    Node* tail = nullptr;
};
