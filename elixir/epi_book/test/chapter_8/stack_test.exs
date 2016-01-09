defmodule Chapter8.StackTest do
  use ExUnit.Case
  doctest Chapter8.Stack

  test "push and peek work" do
    stack = Chapter8.Stack.new
    |> Chapter8.Stack.push(1)
    assert Chapter8.Stack.peek(stack) == 1

    stack = Chapter8.Stack.new
    |> Chapter8.Stack.push(1)
    |> Chapter8.Stack.push(2)
    assert Chapter8.Stack.peek(stack) == 2
  end

  test "peek on an empty stack returns nil" do
    stack = Chapter8.Stack.new
    assert Chapter8.Stack.peek(stack) == nil
  end

  test "pop works" do
    stack = Chapter8.Stack.new
    |> Chapter8.Stack.push(1)
    {_, val} = Chapter8.Stack.pop(stack)
    assert val == 1
  end

  test "pop on an empty stack returns nil" do
    stack = Chapter8.Stack.new
    {_, val} = Chapter8.Stack.pop(stack)
    assert val == nil
  end
end
