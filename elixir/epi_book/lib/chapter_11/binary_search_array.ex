defmodule Chapter11.BinarySearchArray do
  @moduledoc """
  Implement binary search using an Erlang array.
  """

  @doc """
  Takes a sorted array of distinct integers and returns the index of the number,
  or -1 if the array does not contain it
  """
  @spec search(:array, integer) :: integer
  def search(sorted_array, num) do
    _search(sorted_array, num, 0, sorted_array.size)
  end


  @spec _search(:array, integer, integer, integer) :: integer
  # one element to check
  defp _search(arr, num, start_pos, end_pos) when end_pos - start_pos == 0 do
    cond do
      num == arr.get(0) -> start_pos
      true -> -1
    end
  end

  # More than 1 element left to check
  defp _search(arr, num, start_pos, end_pos) do
    mid_idx = div((end_pos + start_pos), 2)
    mid_val = arr.get(mid_idx)
    cond do
      num == mid_val -> mid_idx
      num < mid_val  -> _search(arr, num, start_pos, mid_idx)
      num > mid_val  -> _search(arr, num, mid_idx + 1, end_pos)
    end
  end

end
