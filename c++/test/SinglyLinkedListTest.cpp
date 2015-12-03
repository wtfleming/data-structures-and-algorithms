#include "gmock/gmock.h"
#include "SinglyLinkedList.h"

using namespace testing;

namespace wtf {

  class SinglyLinkedListFixture: public Test {
  public:
    SinglyLinkedList list;
  };


  TEST_F(SinglyLinkedListFixture, HasSizeZeroWhenCreated) {
    ASSERT_THAT(list.size(), Eq(0u));
  }

  TEST_F(SinglyLinkedListFixture, IsEmptyWhenCreated) {
    ASSERT_TRUE(list.isEmpty());
  }

  TEST_F(SinglyLinkedListFixture, IsNotEmptyWhenSizeIsNonZero) {
    list.pushFront(44);
    ASSERT_FALSE(list.isEmpty());
  }

  TEST_F(SinglyLinkedListFixture, HasSizeOneWhenElementAdded) {
    list.pushFront(10);
    ASSERT_THAT(list.size(), Eq(1u));
  }

  TEST_F(SinglyLinkedListFixture, DecreasesSizeWhenElementsRemoved) {
    list.pushFront(10);
    list.pushFront(33);
    list.popFront();
    ASSERT_THAT(list.size(), Eq(1));
    list.popFront();
    ASSERT_THAT(list.size(), Eq(0));
  }

  TEST_F(SinglyLinkedListFixture, ReturnsValueWhenElementRemoved) {
    list.pushFront(10);
    ASSERT_THAT(list.popFront(), Eq(10));
  }

  TEST_F(SinglyLinkedListFixture, ReturnsCorrectHeadWhenValueAdded) {
    list.pushFront(100);
    ASSERT_THAT(list.head(), Eq(100));
  }

  TEST_F(SinglyLinkedListFixture, ReturnsCorrectHeadWhenMultipleValuesAdded) {
    list.pushFront(100);
    list.pushFront(1);
    ASSERT_THAT(list.head(), Eq(1));
  }

    TEST_F(SinglyLinkedListFixture, ReturnsCorrectHeadWhenMultipleValuesAddedAndOneRemoved) {
    list.pushFront(100);
    list.pushFront(1);
    list.popFront();
    ASSERT_THAT(list.head(), Eq(100));
  }

  TEST_F(SinglyLinkedListFixture, ReturnsCorrectNthWhenValueAdded) {
    list.pushFront(440);
    ASSERT_THAT(list.nth(0), Eq(440));
  }

  TEST_F(SinglyLinkedListFixture, ReturnsCorrectNthWhenMultipleValuesAdded) {
    list.pushFront(33);
    list.pushFront(100);
    list.pushFront(1);
    ASSERT_THAT(list.nth(0), Eq(1));
    ASSERT_THAT(list.nth(1), Eq(100));
    ASSERT_THAT(list.nth(2), Eq(33));
  }

   TEST_F(SinglyLinkedListFixture, ReturnsCorrectNthWhenMultipleValuesAddedAndOneRemoved) {
    list.pushFront(100);
    list.pushFront(22);
    list.pushFront(1);
    list.popFront();
    ASSERT_THAT(list.nth(0), Eq(22));
    ASSERT_THAT(list.nth(1), Eq(100));
  }

  TEST_F(SinglyLinkedListFixture, InsertsAtTheBeginning) {
    list.insert(10, 0);
    ASSERT_THAT(list.nth(0), Eq(10));
  }

  TEST_F(SinglyLinkedListFixture, InsertsInTheMiddle) {
    list.pushFront(10);
    list.pushFront(20);
    list.insert(30, 1);
    ASSERT_THAT(list.nth(0), Eq(20));
    ASSERT_THAT(list.nth(1), Eq(30));
    ASSERT_THAT(list.nth(2), Eq(10));
  }

  TEST_F(SinglyLinkedListFixture, InsertsAtTheEnd) {
    list.pushFront(10);
    list.pushFront(20);
    list.insert(30, 2);
    ASSERT_THAT(list.nth(0), Eq(20));
    ASSERT_THAT(list.nth(1), Eq(10));
    ASSERT_THAT(list.nth(2), Eq(30));
  }

  TEST_F(SinglyLinkedListFixture, InsertsIncreaseSize) {
    list.insert(10, 0);
    ASSERT_THAT(list.size(), Eq(1));
    list.insert(20, 1);
    ASSERT_THAT(list.size(), Eq(2));
    list.insert(20, 1);
    ASSERT_THAT(list.size(), Eq(3));
  }

  TEST_F(SinglyLinkedListFixture, RemovesAtTheBeginning) {
    list.insert(10, 0);
    list.remove(0);
    ASSERT_TRUE(list.isEmpty());
  }

  TEST_F(SinglyLinkedListFixture, RemovesInTheMiddle) {
    list.pushFront(10);
    list.pushFront(20);
    list.pushFront(30);
    list.remove(1);
    ASSERT_THAT(list.nth(0), Eq(30));
    ASSERT_THAT(list.nth(1), Eq(10));
  }

  TEST_F(SinglyLinkedListFixture, RemovesAtTheEnd) {
    list.pushFront(10);
    list.pushFront(20);
    list.remove(1);
    ASSERT_THAT(list.nth(0), Eq(20));
    ASSERT_THAT(list.size(), Eq(1));
  }

  TEST_F(SinglyLinkedListFixture, RemovesDecreaseSize) {
    list.insert(10, 0);
    list.insert(20, 1);
    list.insert(30, 1);
    list.remove(1);
    ASSERT_THAT(list.size(), Eq(2));
    list.remove(1);
    ASSERT_THAT(list.size(), Eq(1));
    list.remove(0);
    ASSERT_THAT(list.size(), Eq(0));
  }

  TEST_F(SinglyLinkedListFixture, AllElementsRemovedWhenCleared) {
    list.insert(10, 0);
    list.insert(20, 1);
    list.insert(30, 1);
    list.clear();
    ASSERT_TRUE(list.isEmpty());
  }

  TEST_F(SinglyLinkedListFixture, ClearingAnEmptyListIsANoOp) {
    list.clear();
    ASSERT_TRUE(list.isEmpty());
  }

  TEST_F(SinglyLinkedListFixture, ReversingAnEmptyListIsANoOp) {
    list.reverse();
    ASSERT_TRUE(list.isEmpty());
  }

  TEST_F(SinglyLinkedListFixture, ReversingAListReversesTheOrderOfElements) {
    list.pushFront(10);
    list.pushFront(20);
    list.pushFront(30);
    list.reverse();
    ASSERT_THAT(list.nth(0), Eq(10));
    ASSERT_THAT(list.nth(1), Eq(20));
    ASSERT_THAT(list.nth(2), Eq(30));
  }


}
