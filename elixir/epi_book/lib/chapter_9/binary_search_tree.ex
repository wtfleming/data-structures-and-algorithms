defmodule Chapter9.BinarySearchTree do
  defstruct [:value, :left, :right]
  alias Chapter9.BinarySearchTree, as: BST
  @type t :: %BST{value: number, left: BST.t, right: BST.t} | :empty_node


  @spec new() :: :empty_node
  def new(), do: :empty_node

  @spec insert(BST.t, number) :: BST.t
  def insert(:empty_node, value), do: %BST{value: value, left: :empty_node, right: :empty_node}
  def insert(%BST{value: v, left: l, right: r}, node) do
    cond do
      v == node -> %BST{value: v, left: l, right: r}
      v < node  -> %BST{value: v, left: l, right: insert(r, node)}
      v > node  -> %BST{value: v, left: insert(l, node), right: r}
    end
  end

  @spec left(BST.t):: BST.t
  def left(%BST{left: left}) do
    left
  end

  @spec right(BST.t):: BST.t
  def right(%BST{right: right}) do
    right
  end
end

