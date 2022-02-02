#pragma once

#include <vector>

class Heap{
  public:
    Heap();

    void push(int val);

    void pop();

    int& top();

    int size();

    void print();
  private:
    std::vector<int> vec;
};