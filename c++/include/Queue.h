#ifndef Queue_h
#define Queue_h

#include "DoublyLinkedList.h"
#include <cstddef>

// FIFO Unbounded Queue
// Implemented here with a doubly linked list
namespace wtf {

  class Queue {
  public:
    Queue();

    void push(const int& val);
    int pop();
    int peek() const;
    bool isEmpty() const;
    size_t size() const;

  private:
    DoublyLinkedList mList;
  };
}

#endif // Queue_h
