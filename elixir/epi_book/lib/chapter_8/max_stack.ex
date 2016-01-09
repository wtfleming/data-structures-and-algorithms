defmodule Chapter8.MaxStack do
  defstruct head: []

  @moduledoc """
  Stack that supports max() as an O(1) operation to determine the largest element on the stack
  """

  @doc """
  Construct a empty MaxStack
  """
  def new(), do: %Chapter8.MaxStack{}

  @doc """
  Add an element to the stack
  """
  def push(stack, val) do
    if stack.head == [] do
      %Chapter8.MaxStack{head: [{val, val}]}
    else
      {_node, current_max} = List.first(stack.head)
      if val < current_max do
        %Chapter8.MaxStack{head: [{val, current_max}|stack.head]}
      else
        %Chapter8.MaxStack{head: [{val, val}|stack.head]}
      end
    end
  end

  @doc """
  Remove an element from the stack
  """
  def pop(stack) do
    if stack.head == [] do
      {%Chapter8.MaxStack{head: []}, nil}
    else
      [head|tail] = stack.head
      {val, _current_max} = head
      {%Chapter8.MaxStack{head: tail}, val}
    end
  end

  @doc """
  Return the first element in the stack
  """
  def peek(stack) do
    case List.first(stack.head) do
      nil ->
        nil
      {val, _current_max} ->
        val
    end
  end

  @doc """
  Return the maximum element in the stack
  """
  def max(stack) do
    case List.first(stack.head) do
      nil ->
        nil
      {_val, current_max} ->
        current_max
    end
  end


end
