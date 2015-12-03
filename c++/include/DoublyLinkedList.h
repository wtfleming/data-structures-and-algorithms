#ifndef DoublyLinkedList_h
#define DoublyLinkedList_h

#include <cstddef>

namespace wtf {

  class DoublyLinkedList {
  public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    size_t size() const;
    bool isEmpty() const;
    int head() const;
    int tail() const;
    int nth(size_t pos) const;
    void pushFront(const int& val);
    int popFront();

    void pushBack(const int& val);
    int popBack();

    void insert(const int& val, const size_t& pos);
    void remove(const size_t& pos);
    void clear();
    void reverse();

  private:
    struct Node {
      int data;
      Node *next;
      Node *prev;

    Node(const int& val, Node *nxt, Node *prv) : data(val), next(nxt), prev(prv) {}
    };

    Node *mHead;
    Node *mTail;
    size_t mSize;

    Node* nthNode(size_t pos);
  };

}
#endif // DoublyLinkedList_h
