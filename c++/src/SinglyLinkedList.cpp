#include "SinglyLinkedList.h"

#include <iostream>


namespace wtf {

  SinglyLinkedList::SinglyLinkedList() :
    mHead(nullptr), mSize(0) {
  }

  SinglyLinkedList::~SinglyLinkedList() {
    clear();
  }

  size_t SinglyLinkedList::size() const {
    return mSize;
  }

  bool SinglyLinkedList::isEmpty() const {
    return 0 == mSize;
  }

  void SinglyLinkedList::pushFront(const int& val) {
    Node *newHead  = new Node(val, mHead);
    mHead = newHead;
    mSize++;
  }

  int SinglyLinkedList::popFront() {
    // TODO throw a std::out_of_range if needed
    Node *oldHead = mHead;
    Node *newHead = oldHead->next;
    const int val = oldHead->data;
    mHead = newHead;
    delete oldHead;
    mSize--;
    return val;
  }

  int SinglyLinkedList::head() const {
    // TODO throw a std::out_of_range if needed
    return mHead->data;
  }

  int SinglyLinkedList::nth(size_t pos) const {
    // TODO throw a std::out_of_range if needed
    Node *node = mHead;
    int val = mHead->data;
    while (nullptr != node->next) {
      if (0 == pos) break;
      node = node->next;
      val = node->data;
      pos--;
    }
    return val;
  }

  SinglyLinkedList::Node* SinglyLinkedList::nthNode(size_t pos) {
    // TODO throw a std::out_of_range if needed
    Node *node = mHead;
    while (0 != pos) {
      node = node->next;
      pos--;
    }
    return node;
  }

  void SinglyLinkedList::insert(const int& val, const size_t& pos) {
    // TODO throw a std::out_of_range if needed
    if (isEmpty()) {
      pushFront(val);
    } else {
      Node *prevNode = nthNode(pos - 1);
      Node *newNode = new Node(val, prevNode->next);
      prevNode->next = newNode;
      mSize++;
    }
  }

  void SinglyLinkedList::remove(const size_t& pos) {
    // TODO throw a std::out_of_range if needed
    if (1 == mSize) {
      delete mHead;
      mHead = nullptr;
    } else {
      Node *prevNode = nthNode(pos - 1);
      Node *nodeToDelete = prevNode->next;
      prevNode->next = nodeToDelete->next;
      delete nodeToDelete;
    }
    mSize--;
  }

  void SinglyLinkedList::clear() {
    while (!isEmpty()) {
      popFront();
    }
  }

  void SinglyLinkedList::reverse() {
    Node *prev = nullptr;
    Node *it = mHead;
    while (nullptr != it) {
      Node *next = it->next;
      it->next = prev;
      prev = it;
      it = next;
    }
    mHead = prev;
  }

}
