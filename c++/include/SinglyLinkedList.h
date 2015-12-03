#ifndef SinglyLinkedList_h
#define SinglyLinkedList_h

#include <cstddef>

namespace wtf {

  class SinglyLinkedList {
  public:
    SinglyLinkedList();
    ~SinglyLinkedList();
    size_t size() const;
    bool isEmpty() const;
    int head() const;
    int nth(size_t pos) const;
    void pushFront(const int& val);
    int popFront();

    void insert(const int& val, const size_t& pos);
    void remove(const size_t& pos);
    void clear();

    void reverse();
    
  private:
    struct Node {
      int data;
      Node *next;

      Node(const int& val, Node *nxt) : data(val), next(nxt) {}
    };

    Node *mHead;
    size_t mSize;

    Node* nthNode(size_t pos);
  };

}
#endif // SinglyLinkedList_h
