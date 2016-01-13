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


  @spec contains?(BST.t, number) :: boolean
  def contains?(:empty_node, _), do: false
  def contains?(%BST{value: value, left: left, right: right}, number) do
    cond do
      value == number -> true
      number < value  -> contains?(left, number)
      number > value  -> contains?(right, number)
    end
  end

  @spec in_order_traversal(BST.t) :: [number]
  def in_order_traversal(tree), do: _in_order_traversal(tree, [])

  @spec _in_order_traversal(BST.t, [number]) :: [number]
  defp _in_order_traversal(:empty_node, _), do: []
  defp _in_order_traversal(%BST{value: value, left: left, right: right}, acc) do
    l = _in_order_traversal(left, acc)
    r = _in_order_traversal(right, acc)
    l ++ [value] ++ r
  end

  @spec min(BST.t) :: number | nil
  def min(:empty_node), do: nil
  def min(%BST{value: value, left: :empty_node}), do: value
  def min(%BST{left: left}), do: min(left)

  @spec max(BST.t) :: number | nil
  def max(:empty_node), do: nil
  def max(%BST{value: value, right: :empty_node}), do: value
  def max(%BST{right: right}), do: max(right)


  @spec lowest_common_ancestor(BST.t, number, number) :: number
  def lowest_common_ancestor(tree, a, b) when a < b, do: lca(tree, a, b)
  def lowest_common_ancestor(tree, a, b) when a > b, do: lca(tree, b, a)


  @spec lca(BST.t, number, number) :: number
  defp lca(%BST{value: value}, smaller, larger) when smaller < value and larger > value do
    value
  end

  defp lca(%BST{value: value, left: left}, smaller, larger) when smaller < value and larger < value do
    lca(left, smaller, larger)
  end

  defp lca(%BST{value: value, right: right}, smaller, larger) when smaller > value and larger > value do
    lca(right, smaller, larger)
  end

  defp lca(%BST{value: value}, smaller, larger) when smaller == value or larger == value do
    value
  end

end

