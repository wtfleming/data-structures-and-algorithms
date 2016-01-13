defmodule Chapter9.BinarySearchTreeTest do
  use ExUnit.Case
  alias Chapter9.BinarySearchTree, as: BST

  test "a new list has an empty head" do
    tree = BST.new
    assert tree == :empty_node
  end

  test "insert works" do
    tree = BST.new
    |> BST.insert(10)
    |> BST.insert(10)
    |> BST.insert(5)
    |> BST.insert(6)
    |> BST.insert(11)

    assert tree.value == 10

    node = BST.left(tree)
    assert node.value == 5

    node = BST.right(tree)
    assert node.value == 11

    node = tree
    |> BST.left
    |> BST.right
    assert node.value == 6
  end

  test "contains?" do
    tree = BST.new
    |> BST.insert(10)
    |> BST.insert(5)
    |> BST.insert(6)
    |> BST.insert(11)

    assert BST.contains?(tree, 10) == true
    assert BST.contains?(tree, 5) == true
    assert BST.contains?(tree, 6) == true
    assert BST.contains?(tree, 11) == true
    assert BST.contains?(tree, 12) == false
    assert BST.contains?(tree, 1) == false
  end

  test "in_order_traversal" do
    assert BST.in_order_traversal(BST.new) == []

    tree = BST.new
    |> BST.insert(15)
    |> BST.insert(5)
    |> BST.insert(25)
    |> BST.insert(6)
    |> BST.insert(11)
    |> BST.insert(1)
    |> BST.insert(24)
    |> BST.insert(23)
    assert BST.in_order_traversal(tree) == [1, 5, 6, 11, 15, 23, 24, 25]
  end


  test "min" do
    assert BST.min(BST.new) == nil

    tree = BST.new
    |> BST.insert(15)
    |> BST.insert(5)
    |> BST.insert(25)
    |> BST.insert(6)
    |> BST.insert(1)
    |> BST.insert(24)
    |> BST.insert(23)
    assert BST.min(tree) == 1
  end

  test "max" do
    assert BST.min(BST.new) == nil

    tree = BST.new
    |> BST.insert(15)
    |> BST.insert(5)
    |> BST.insert(25)
    |> BST.insert(6)
    |> BST.insert(1)
    |> BST.insert(24)
    |> BST.insert(23)
    assert BST.max(tree) == 25
  end

end
