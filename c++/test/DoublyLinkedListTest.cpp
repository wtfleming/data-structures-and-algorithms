#include "gmock/gmock.h"
#include "DoublyLinkedList.h"

using namespace testing;

namespace wtf {

  class DoublyLinkedListFixture: public Test {
  public:
    DoublyLinkedList list;
  };

  TEST_F(DoublyLinkedListFixture, HasSizeZeroWhenCreated) {
    ASSERT_THAT(list.size(), Eq(0u));
  }

  TEST_F(DoublyLinkedListFixture, IsEmptyWhenCreated) {
    ASSERT_TRUE(list.isEmpty());
  }

  TEST_F(DoublyLinkedListFixture, IsNotEmptyWhenElementAddedToFrontOfEmptyList) {
    list.pushFront(44);
    ASSERT_FALSE(list.isEmpty());
  }

  TEST_F(DoublyLinkedListFixture, IsNotEmptyWhenElementAddedToEndOfEmptyList) {
    list.pushBack(44);
    ASSERT_FALSE(list.isEmpty());
  }

  TEST_F(DoublyLinkedListFixture, HasSizeOneWhenElementAddedToFrontOfEmptyList) {
    list.pushFront(10);
    ASSERT_THAT(list.size(), Eq(1u));
  }

  TEST_F(DoublyLinkedListFixture, HasSizeOneWhenElementAddedToEndOfEmptyList) {
    list.pushBack(10);
    ASSERT_THAT(list.size(), Eq(1u));
  }

  TEST_F(DoublyLinkedListFixture, HasSizeTwoWhenElementAddedToFrontOfNonEmptyList) {
    list.pushFront(10);
    list.pushFront(20);
    ASSERT_THAT(list.size(), Eq(2u));
  }

  TEST_F(DoublyLinkedListFixture, HasSizeTwoWhenElementAddedToEndOfNonEmptyList) {
    list.pushBack(10);
    list.pushBack(20);
    ASSERT_THAT(list.size(), Eq(2u));
  }

  TEST_F(DoublyLinkedListFixture, DecreasesSizeWhenElementsRemovedFromFront) {
    list.pushFront(10);
    list.pushFront(33);
    list.popFront();
    ASSERT_THAT(list.size(), Eq(1));
    list.popFront();
    ASSERT_THAT(list.size(), Eq(0));
  }

  TEST_F(DoublyLinkedListFixture, ReturnsValueWhenElementRemovedFromFront) {
    list.pushFront(10);
    ASSERT_THAT(list.popFront(), Eq(10));
  }

  TEST_F(DoublyLinkedListFixture, ReturnsCorrectHeadWhenValueAddedToFrontOfEmptyList) {
    list.pushFront(100);
    ASSERT_THAT(list.head(), Eq(100));
  }

  TEST_F(DoublyLinkedListFixture, ReturnsCorrectTailWhenValueAddedToFrontOfEmptyList) {
    list.pushFront(100);
    ASSERT_THAT(list.tail(), Eq(100));
  }

  TEST_F(DoublyLinkedListFixture, ReturnsCorrectHeadWhenMultipleValuesAddedToFront) {
    list.pushFront(100);
    list.pushFront(1);
    ASSERT_THAT(list.head(), Eq(1));
  }

  TEST_F(DoublyLinkedListFixture, ReturnsCorrectTailWhenMultipleValuesAddedToFront) {
    list.pushFront(100);
    list.pushFront(1);
    ASSERT_THAT(list.tail(), Eq(100));
  }

  TEST_F(DoublyLinkedListFixture, ReturnsCorrectHeadWhenMultipleValuesAddedAndOneRemoved) {
    list.pushFront(100);
    list.pushFront(1);
    list.popFront();
    ASSERT_THAT(list.head(), Eq(100));
  }

  TEST_F(DoublyLinkedListFixture, ReturnsCorrectTailWhenMultipleValuesAddedAndOneRemovedFromFront) {
    list.pushFront(100);
    list.pushFront(1);
    list.popFront();
    ASSERT_THAT(list.tail(), Eq(100));
  }

  TEST_F(DoublyLinkedListFixture, ReturnsCorrectNthWhenValueAddedToFront) {
    list.pushFront(440);
    ASSERT_THAT(list.nth(0), Eq(440));
  }

  TEST_F(DoublyLinkedListFixture, ReturnsCorrectNthWhenMultipleValuesAdded) {
    list.pushFront(33);
    list.pushFront(100);
    list.pushFront(1);
    ASSERT_THAT(list.nth(0), Eq(1));
    ASSERT_THAT(list.nth(1), Eq(100));
    ASSERT_THAT(list.nth(2), Eq(33));
  }

   TEST_F(DoublyLinkedListFixture, ReturnsCorrectNthWhenMultipleValuesAddedAndOneRemoved) {
    list.pushFront(100);
    list.pushFront(22);
    list.pushFront(1);
    list.popFront();
    ASSERT_THAT(list.nth(0), Eq(22));
    ASSERT_THAT(list.nth(1), Eq(100));
  }

  TEST_F(DoublyLinkedListFixture, ReturnsCorrectHeadWhenValueAddedToEndOfEmptyList) {
    list.pushBack(100);
    ASSERT_THAT(list.head(), Eq(100));
  }

  TEST_F(DoublyLinkedListFixture, ReturnsCorrectTailWhenValueAddedToEndOfEmptyList) {
    list.pushBack(100);
    ASSERT_THAT(list.tail(), Eq(100));
  }

  TEST_F(DoublyLinkedListFixture, DecreasesSizeWhenElementsRemovedFromBack) {
    list.pushFront(10);
    list.pushBack(33);
    list.popBack();
    ASSERT_THAT(list.size(), Eq(1));
    list.popBack();
    ASSERT_THAT(list.size(), Eq(0));
  }

  TEST_F(DoublyLinkedListFixture, ReturnsValueWhenElementRemovedFromBack) {
    list.pushBack(10);
    ASSERT_THAT(list.popBack(), Eq(10));
  }


  TEST_F(DoublyLinkedListFixture, InsertsAtTheBeginning) {
    list.insert(10, 0);
    ASSERT_THAT(list.nth(0), Eq(10));
  }

  TEST_F(DoublyLinkedListFixture, InsertsInTheMiddle) {
    list.pushFront(10);
    list.pushFront(20);
    list.insert(30, 1);
    ASSERT_THAT(list.nth(0), Eq(20));
    ASSERT_THAT(list.nth(1), Eq(30));
    ASSERT_THAT(list.nth(2), Eq(10));
  }

  TEST_F(DoublyLinkedListFixture, InsertsAtTheEnd) {
    list.pushFront(10);
    list.pushFront(20);
    list.insert(30, 2);
    ASSERT_THAT(list.nth(0), Eq(20));
    ASSERT_THAT(list.nth(1), Eq(10));
    ASSERT_THAT(list.nth(2), Eq(30));
  }

  TEST_F(DoublyLinkedListFixture, InsertsIncreaseSize) {
    list.insert(10, 0);
    ASSERT_THAT(list.size(), Eq(1));
    list.insert(20, 1);
    ASSERT_THAT(list.size(), Eq(2));
    list.insert(20, 1);
    ASSERT_THAT(list.size(), Eq(3));
  }

  TEST_F(DoublyLinkedListFixture, RemovesAtTheBeginning) {
    list.insert(10, 0);
    list.remove(0);
    ASSERT_TRUE(list.isEmpty());
  }

  TEST_F(DoublyLinkedListFixture, RemovesInTheMiddle) {
    list.pushFront(10);
    list.pushFront(20);
    list.pushFront(30);
    list.remove(1);
    ASSERT_THAT(list.nth(0), Eq(30));
    ASSERT_THAT(list.nth(1), Eq(10));
  }

  TEST_F(DoublyLinkedListFixture, RemovesAtTheEnd) {
    list.pushFront(10);
    list.pushFront(20);
    list.remove(1);
    ASSERT_THAT(list.nth(0), Eq(20));
    ASSERT_THAT(list.size(), Eq(1));
  }

  TEST_F(DoublyLinkedListFixture, RemovesDecreaseSize) {
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

  TEST_F(DoublyLinkedListFixture, AllElementsRemovedWhenCleared) {
    list.insert(10, 0);
    list.insert(20, 1);
    list.insert(30, 1);
    list.clear();
    ASSERT_TRUE(list.isEmpty());
  }

  TEST_F(DoublyLinkedListFixture, ClearingAnEmptyListIsANoOp) {
    list.clear();
    ASSERT_TRUE(list.isEmpty());
  }

  TEST_F(DoublyLinkedListFixture, ReversingAListReversesTheOrderOfElements) {
    list.pushFront(10);
    list.pushFront(20);
    list.pushFront(30);
    list.reverse();
    ASSERT_THAT(list.nth(0), Eq(10));
    ASSERT_THAT(list.nth(1), Eq(20));
    ASSERT_THAT(list.nth(2), Eq(30));
  }

}
