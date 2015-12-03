#ifndef Stack_h
#define Stack_h

#include "SinglyLinkedList.h"
#include <cstddef>

// LIFO Stack
// Implemented here with a singly linked list
namespace wtf {

  class Stack {
  public:
    Stack();

    void push(const int& val);
    int pop();
    int peek() const;
    bool isEmpty() const;
    size_t size() const;

  private:
    SinglyLinkedList mList;
  };
}

#endif // Stack_h
