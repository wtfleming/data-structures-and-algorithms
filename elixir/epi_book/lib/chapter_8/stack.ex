defmodule Chapter8.Stack do
  defstruct head: []
  @type t :: %Chapter8.Stack{head: [any]}

  @moduledoc """
  Stack implementation.
  """

  @doc """
  Construct an empty stack.
  """
  @spec new() :: Chapter8.Stack.t
  def new(), do: %Chapter8.MaxStack{}

  @doc """
  Add an element to the stack.
  """
  @spec push(Chapter8.Stack.t, any) :: Chapter8.Stack.t
  def push(stack, val) do
    %Chapter8.MaxStack{head: [val|stack.head]}
  end

  @doc """
  Remove an element from the stack.
  """
  @spec pop(t) :: {Chapter8.Stack.t, any}
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
  @spec peek(Chapter8.Stack.t) :: any
  def peek(stack) do
    List.first(stack.head)
  end

end
