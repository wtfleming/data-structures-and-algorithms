defmodule FibonacciSequenceTest do
  use ExUnit.Case
  import FibonacciSequence

  test "fib" do
    assert fib(0) == 0
    assert fib(1) == 1
    assert fib(2) == 1
    assert fib(3) == 2
    assert fib(4) == 3
    assert fib(5) == 5
    assert fib(6) == 8
    assert fib(7) == 13
  end
end
