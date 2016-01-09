defmodule Chapter8.MaxStackTest do
  use ExUnit.Case
  doctest Chapter8.MaxStack

  test "push and peek work" do
    stack = Chapter8.MaxStack.new
    |> Chapter8.MaxStack.push(1)
    assert Chapter8.MaxStack.peek(stack) == 1

    stack = Chapter8.MaxStack.new
    |> Chapter8.MaxStack.push(1)
    |> Chapter8.MaxStack.push(2)
    assert Chapter8.MaxStack.peek(stack) == 2
  end

  test "peek on an empty stack returns nil" do
    stack = Chapter8.MaxStack.new
    assert Chapter8.MaxStack.peek(stack) == nil
  end

  test "pop works" do
    stack = Chapter8.MaxStack.new
    |> Chapter8.MaxStack.push(1)
    {_stack, val} = Chapter8.MaxStack.pop(stack)
    assert val == 1
  end

  test "pop on an empty stack returns nil" do
    stack = Chapter8.MaxStack.new
    {_stack, val} = Chapter8.MaxStack.pop(stack)
    assert val == nil
  end

  test "max works" do
    # []
    stack = Chapter8.MaxStack.new

    # [1]
    stack = Chapter8.MaxStack.push(stack, 1)
    assert Chapter8.MaxStack.max(stack) == 1

    # [1, 2]
    stack = Chapter8.MaxStack.push(stack, 2)
    assert Chapter8.MaxStack.max(stack) == 2

    # [1, 2, 1]
    stack = Chapter8.MaxStack.push(stack, 1)
    assert Chapter8.MaxStack.max(stack) == 2

    # [1, 2]
    {stack, _val} = Chapter8.MaxStack.pop(stack)
    assert Chapter8.MaxStack.max(stack) == 2

    # [1]
    {stack, _val} = Chapter8.MaxStack.pop(stack)
    assert Chapter8.MaxStack.max(stack) == 1
  end

  test "max on an empty stack returns nil" do
    stack = Chapter8.MaxStack.new
    assert Chapter8.MaxStack.max(stack) == nil
  end


end
