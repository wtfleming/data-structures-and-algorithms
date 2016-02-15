defmodule Misc do

  @spec reverse_list(list):: list
  def reverse_list(l) do
    _reverse_list(l, [])
  end

  @spec _reverse_list(list, list):: list
  defp _reverse_list([], acc), do: acc
  defp _reverse_list([h|t], acc) do
    _reverse_list(t, [h|acc])
  end

end
