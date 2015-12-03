#include "gmock/gmock.h"
#include "Stack.h"

using namespace testing;

namespace wtf {

  class StackFixture: public Test {
  public:
    Stack stack;
  };

  TEST_F(StackFixture, HasSizeZeroWhenCreated) {
    ASSERT_THAT(stack.size(), Eq(0u));
  }

  TEST_F(StackFixture, IsEmptyWhenCreated) {
    ASSERT_TRUE(stack.isEmpty());
  }

  TEST_F(StackFixture, IsNotEmptyWhenSizeIsNonZero) {
    stack.push(44);
    ASSERT_FALSE(stack.isEmpty());
  }

  TEST_F(StackFixture, HasSizeOneWhenElementAdded) {
    stack.push(10);
    ASSERT_THAT(stack.size(), Eq(1u));
  }

  TEST_F(StackFixture, DecreasesSizeWhenElementsRemoved) {
    stack.push(10);
    stack.push(33);
    stack.pop();
    ASSERT_THAT(stack.size(), Eq(1u));
    stack.pop();
    ASSERT_THAT(stack.size(), Eq(0u));
  }

  TEST_F(StackFixture, ReturnsValueWhenElementRemoved) {
    stack.push(10);
    ASSERT_THAT(stack.pop(), Eq(10u));
  }

  TEST_F(StackFixture, ReturnsValueWhenPeekingAtTheFront) {
    stack.push(10);
    ASSERT_THAT(stack.peek(), Eq(10u));
  }

  TEST_F(StackFixture, SizeDoesNotChangeWhenPeekingAtTheFront) {
    stack.push(10);
    stack.peek();
    ASSERT_THAT(stack.size(), Eq(1u));
  }

  TEST_F(StackFixture, ValuesArePeekedLastInFirstOut) {
    stack.push(10);
    stack.push(20);
    ASSERT_THAT(stack.peek(), Eq(20));
  }

  TEST_F(StackFixture, ValuesAreRemovedLastInFirstOut) {
    stack.push(10);
    stack.push(20);
    ASSERT_THAT(stack.pop(), Eq(20));
  }

}
