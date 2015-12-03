#include "gmock/gmock.h"
#include "Queue.h"

using namespace testing;

namespace wtf {

  class QueueFixture: public Test {
  public:
    Queue queue;
  };

  TEST_F(QueueFixture, HasSizeZeroWhenCreated) {
    ASSERT_THAT(queue.size(), Eq(0u));
  }

  TEST_F(QueueFixture, IsEmptyWhenCreated) {
    ASSERT_TRUE(queue.isEmpty());
  }

  TEST_F(QueueFixture, IsNotEmptyWhenSizeIsNonZero) {
    queue.push(44);
    ASSERT_FALSE(queue.isEmpty());
  }

  TEST_F(QueueFixture, HasSizeOneWhenElementAdded) {
    queue.push(10);
    ASSERT_THAT(queue.size(), Eq(1u));
  }

  TEST_F(QueueFixture, DecreasesSizeWhenElementsRemoved) {
    queue.push(10);
    queue.push(33);
    queue.pop();
    ASSERT_THAT(queue.size(), Eq(1u));
    queue.pop();
    ASSERT_THAT(queue.size(), Eq(0u));
  }

  TEST_F(QueueFixture, ReturnsValueWhenElementRemoved) {
    queue.push(10);
    ASSERT_THAT(queue.pop(), Eq(10u));
  }

  TEST_F(QueueFixture, ReturnsValueWhenPeekingAtTheFront) {
    queue.push(10);
    ASSERT_THAT(queue.peek(), Eq(10u));
  }

  TEST_F(QueueFixture, SizeDoesNotChangeWhenPeekingAtTheFront) {
    queue.push(10);
    queue.peek();
    ASSERT_THAT(queue.size(), Eq(1u));
  }

  TEST_F(QueueFixture, ValuesArePeekedFirstInFirstOut) {
    queue.push(10);
    queue.push(20);
    ASSERT_THAT(queue.peek(), Eq(10));
  }

  TEST_F(QueueFixture, ValuesAreRemovedFirstInFirstOut) {
    queue.push(10);
    queue.push(20);
    ASSERT_THAT(queue.pop(), Eq(10));
  }

}
