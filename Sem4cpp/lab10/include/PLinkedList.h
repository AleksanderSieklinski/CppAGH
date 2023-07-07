#pragma once
#include "Node.h"

template<typename T>
class PLinkedList {
  Node<T> * head_;
  int size_;
public:
    //constructor of a LinkedList, assinging beginning values to all elements
    PLinkedList() : head_(nullptr), size_(0) {}
    //destructor of a LinkedList, deleting all elements individually
    ~PLinkedList() {
        Node<T> * n = head_;
        for (int i = 0; i < size_; i++) {
            Node<T> * tmp = n->next();
            delete n;
            n = tmp;
        }
    }
    //AddFront method adds a new Node to the front of the list. The node is copied, not just assigned.
    PLinkedList<T> & addFront(Node<T> * n) {
        Node<T> * tmp = new Node<T>(n->data());
      if (head_ == nullptr) {
        head_ = tmp;
      } else {
        tmp->next(head_);
        head_ = tmp;
      }
      size_++;
      return *this;
    }
    //head method returns the head pointer
    Node<T> * head() { return head_; }
    //size method returns the size of the LinkedList
    int size() { return size_; }
    //operator << prints the contents of a list
    friend std::ostream & operator<<(std::ostream & os, const PLinkedList<T> & list) {
      Node<T> * n = list.head_;
      for (int i = 0; i < list.size_; i++) {
        if (i > 0) os << " -> ";
        os << n->data();
        n = n->next();
      }
      return os;
    }
    //copying constructor copies the list from argument to this argument
    PLinkedList(const PLinkedList<T> & list) : head_(nullptr), size_(0) {
        std::cout << "--- copying list: " << list << std::endl;
        Node<T> * n = list.head_;
        for (int i = 0; i < list.size_; i++) {
            for (int j = 0; j < list.size_ - i - 1; j++) {
                n = n->next();
            }
            addFront(n);
            n = list.head_;
        }
    }
    //moving constructor moves the list from argument to this argument and assigns null values to argument list
    PLinkedList(PLinkedList<T> && list) : head_(nullptr), size_(0) {
      std::cout << "--- moving list: " << list << std::endl;
      head_ = list.head_;
      size_ = list.size_;
      list.head_ = nullptr;
      list.size_ = 0;
    }
};