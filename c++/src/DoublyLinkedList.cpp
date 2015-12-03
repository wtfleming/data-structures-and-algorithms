#include "DoublyLinkedList.h"

namespace wtf {

  DoublyLinkedList::DoublyLinkedList() :
    mHead(nullptr), mTail(nullptr), mSize(0) {
  }

  DoublyLinkedList::~DoublyLinkedList() {
    clear();
  }

  size_t DoublyLinkedList::size() const {
    return mSize;
  }

  bool DoublyLinkedList::isEmpty() const {
    return 0 == mSize;
  }

  void DoublyLinkedList::pushFront(const int& val) {
    Node *oldHead = mHead;
    Node *newHead = new Node(val, oldHead, nullptr);

    mHead = newHead;
    if (nullptr == mTail) {
      // Only update the tail if the list was empty
      mTail = newHead;
    }

    if (nullptr != mHead->next) {
      // Update the now second node's prev link to point to the
      // newly created node in front of it.
      mHead->next->prev = mHead;
    }
    mSize++;
  }

  void DoublyLinkedList::pushBack(const int& val) {
    Node *newTail;
    if(isEmpty()) {
      newTail = new Node(val, nullptr, nullptr);
      mHead = newTail;
    } else {
      newTail = new Node(val, nullptr, mTail);
      mTail->next = newTail;
    }
    mTail = newTail;
    mSize++;
  }

  int DoublyLinkedList::popFront() {
    // TODO throw a std::out_of_range if needed
    Node *oldHead = mHead;
    Node *newHead = oldHead->next;
    if (nullptr != newHead) {
      newHead->prev = nullptr;
    }
    const int val = oldHead->data;
    mHead = newHead;
    delete oldHead;
    mSize--;
    if (0 == mSize) {
      mTail = nullptr;
    }
    return val;
  }

  int DoublyLinkedList::popBack() {
    // TODO throw a std::out_of_range if needed
    Node *oldTail = mTail;
    Node *newTail = nullptr;
    const int val = oldTail->data;

    if (nullptr != oldTail->prev) {
      newTail = oldTail->prev;
      newTail->next = nullptr;
    }
    mTail = newTail;
    delete oldTail;
    mSize--;
    return val;
  }

  int DoublyLinkedList::head() const {
    // TODO throw a std::out_of_range if needed
    return mHead->data;
  }

  int DoublyLinkedList::tail() const {
    // TODO throw a std::out_of_range if needed
    return mTail->data;
  }

  int DoublyLinkedList::nth(size_t pos) const {
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

  DoublyLinkedList::Node* DoublyLinkedList::nthNode(size_t pos) {
    // TODO throw a std::out_of_range if needed
    Node *node = mHead;
    while (0 != pos) {
      node = node->next;
      pos--;
    }
    return node;
  }

  void DoublyLinkedList::insert(const int& val, const size_t& pos) {
    // TODO throw a std::out_of_range if needed
    if (0 == pos) {
      // Inserting at head
      pushFront(val);
    } else if (pos == mSize) {
      // Inserting at tail
      pushBack(val);
    } else {
      // Inserting in the middle
      Node *next = nthNode(pos);
      Node *prev = next->prev;
      Node *newNode = new Node(val, next, prev);
      prev->next = newNode;
      mSize++;
    }
  }

  void DoublyLinkedList::remove(const size_t& pos) {
    // TODO throw a std::out_of_range if needed
    if (0 == pos) {
      // Removing head
      popFront();
    } else if (pos + 1 == mSize) {
      // Removing tail
      popBack();
    } else {
      // Removing from middle
      Node *toRemove = nthNode(pos);
      Node *prev = toRemove->prev;
      Node *next = toRemove->next;

      prev->next = next;
      next->prev = prev;
      delete toRemove;
      mSize--;
    }
  }

  void DoublyLinkedList::clear() {
    while (!isEmpty()) {
      popFront();
    }
  }

  void DoublyLinkedList::reverse() {
    Node *it = mHead;
    Node *tmp;
    while (nullptr != it) {
      tmp = it->next;
      it->next = it->prev;
      it->prev = tmp;
      it = it->prev;
    }
    tmp = mHead;
    mHead = mTail;
    mTail = mHead;
  }
}
