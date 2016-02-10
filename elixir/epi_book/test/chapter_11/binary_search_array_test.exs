defmodule Chapter11.BinarySearchArrayTest do
  use ExUnit.Case

  test "search empty array" do
    arr = :array.from_list([])
    assert Chapter11.BinarySearchArray.search(arr, 1) == -1
    assert Chapter11.BinarySearchArray.search(arr, 6) == -1
  end

  test "search array with an one element" do
    arr = :array.from_list([5])
    assert Chapter11.BinarySearchArray.search(arr, 5) == 0
    assert Chapter11.BinarySearchArray.search(arr, 6) == -1
  end

  test "search array with an two elements" do
    arr = :array.from_list([1,5])
    assert Chapter11.BinarySearchArray.search(arr, 1) == 0
    assert Chapter11.BinarySearchArray.search(arr, 5) == 1
    assert Chapter11.BinarySearchArray.search(arr, 6) == -1
  end


  test "search array with an odd number of elements" do
    arr = :array.from_list([1,2,3,4,5,6,7,8,9])

    assert Chapter11.BinarySearchArray.search(arr, 1) == 0
    assert Chapter11.BinarySearchArray.search(arr, 2) == 1
    assert Chapter11.BinarySearchArray.search(arr, 3) == 2
    assert Chapter11.BinarySearchArray.search(arr, 4) == 3
    assert Chapter11.BinarySearchArray.search(arr, 5) == 4
    assert Chapter11.BinarySearchArray.search(arr, 6) == 5
    assert Chapter11.BinarySearchArray.search(arr, 7) == 6
    assert Chapter11.BinarySearchArray.search(arr, 8) == 7
    assert Chapter11.BinarySearchArray.search(arr, 9) == 8
    assert Chapter11.BinarySearchArray.search(arr, 0) == -1
    assert Chapter11.BinarySearchArray.search(arr, 10) == -1
  end

    test "search array with an even number of elements" do
    arr = :array.from_list([1,2,3,4,5,6,7,8])

    assert Chapter11.BinarySearchArray.search(arr, 1) == 0
    assert Chapter11.BinarySearchArray.search(arr, 2) == 1
    assert Chapter11.BinarySearchArray.search(arr, 3) == 2
    assert Chapter11.BinarySearchArray.search(arr, 4) == 3
    assert Chapter11.BinarySearchArray.search(arr, 5) == 4
    assert Chapter11.BinarySearchArray.search(arr, 6) == 5
    assert Chapter11.BinarySearchArray.search(arr, 7) == 6
    assert Chapter11.BinarySearchArray.search(arr, 8) == 7
    assert Chapter11.BinarySearchArray.search(arr, 9) == -1
    assert Chapter11.BinarySearchArray.search(arr, 0) == -1
    assert Chapter11.BinarySearchArray.search(arr, 10) == -1
  end


end
