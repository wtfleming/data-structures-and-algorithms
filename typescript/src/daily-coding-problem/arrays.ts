// Given an array of integers, return a a new array such that each element at index i pf the new array
// is the product of all the numbers in the original array except the one at i
export function getProductOfAllOtherElements(arr: number[]) {
  const totalProduct = arr.reduce((acc, currentVal) => acc * currentVal);
  return arr.map(x => totalProduct / x);
}
