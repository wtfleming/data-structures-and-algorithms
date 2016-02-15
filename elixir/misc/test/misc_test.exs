defmodule MiscTest do
  use ExUnit.Case
  doctest Misc

  test "Reversing a list" do
    assert Misc.reverse_list([]) == []
    assert Misc.reverse_list([0]) == [0]
    assert Misc.reverse_list([0,1]) == [1,0]
    assert Misc.reverse_list([0,1,2,3,4]) == [4,3,2,1,0]
  end
end
