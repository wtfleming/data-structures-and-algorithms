#include "Queue.h"

namespace wtf {

  Queue::Queue()  {

  }

  size_t Queue::size() const {
    return mList.size();
  }

  bool Queue::isEmpty() const {
    return mList.isEmpty();
  }

  void Queue::push(const int& val) {
    mList.pushFront(val);
  }

  int Queue::pop() {
    return mList.popBack();
  }

  int Queue::peek() const {
    return mList.tail();
  }
}
