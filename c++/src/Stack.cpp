#include "Stack.h"

namespace wtf {

  Stack::Stack()  {

  }

  size_t Stack::size() const {
    return mList.size();
  }

  bool Stack::isEmpty() const {
    return mList.isEmpty();
  }

  void Stack::push(const int& val) {
    mList.pushFront(val);
  }

  int Stack::pop() {
    return mList.popFront();
  }

  int Stack::peek() const {
    return mList.head();
  }
}
