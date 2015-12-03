project(wtfDataStructures)
cmake_minimum_required(VERSION 2.6)

include_directories(
  $ENV{GMOCK_HOME}/include
  $ENV{GMOCK_HOME}/gtest/include
  ${wtfDataStructures_SOURCE_DIR}/include)

link_directories(
  $ENV{GMOCK_HOME}/mybuild
  $ENV{GMOCK_HOME}/gtest/mybuild)

add_definitions(-std=c++0x)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

set(sources
   src/main.cpp
   src/SinglyLinkedList.cpp
   src/Stack.cpp
   src/Queue.cpp
   src/DoublyLinkedList.cpp)

set(tests
   test/SinglyLinkedListTest.cpp
   test/StackTest.cpp
   test/QueueTest.cpp
   test/DoublyLinkedListTest.cpp)

add_executable(test ${sources} ${tests})
target_link_libraries(test pthread)
target_link_libraries(test gmock)
target_link_libraries(test gtest)

