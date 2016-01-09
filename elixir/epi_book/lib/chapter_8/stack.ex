defmodule Chapter8.Stack do
  defstruct head: []

  @moduledoc """
  Stack implementation.
  """

  @doc """
  Construct an empty stack.
  """
  def new(), do: %Chapter8.MaxStack{}

  @doc """
  Add an element to the stack.
  """
  def push(stack, val) do
    %Chapter8.MaxStack{head: [val|stack.head]}
  end

  @doc """
  Remove an element from the stack.
  """
  def pop(stack) do
    if stack.head == [] do
      {%Chapter8.MaxStack{head: []}, nil}
    else
      [head|tail] = stack.head
      {%Chapter8.MaxStack{head: tail}, head}
    end
  end

  @doc """
  Return the first element in the stack
  """
  def peek(stack) do
    List.first(stack.head)
  end

end
