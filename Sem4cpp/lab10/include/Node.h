#pragma once
#include <iostream>
#include <vector>

template<typename T>
//Node class is an element of a linked list
class Node {
  T data_;
  Node<T> * next_;
public:
    //constructor of a Node, taking data as an argument
    Node(T data) : data_(data), next_(nullptr) {}
    //next method, returning the next element to the node
    Node<T> * next() { return next_; }
    //next void method,assigning an argument as a next node
    void next(Node<T> * n) { next_ = n; }
    //data method returning data of a node
    T data() { return data_; }
    //print method printing data of a node on screen
    void print() { std::cout << data_; }
    };