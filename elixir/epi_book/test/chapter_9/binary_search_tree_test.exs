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


end
