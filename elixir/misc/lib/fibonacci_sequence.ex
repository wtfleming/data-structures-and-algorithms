defmodule FibonacciSequence do

  @doc """
  Returns the nth number in Fibonacci sequences with an input n
  """
  @spec fib(non_neg_integer) :: non_neg_integer
  def fib(x), do: _fib(0, 1, x)

  @spec _fib(non_neg_integer, pos_integer, non_neg_integer) :: non_neg_integer
  defp _fib(x, _, 0), do: x
  defp _fib(x, y, num), do: _fib(y, x + y, num - 1)

end
