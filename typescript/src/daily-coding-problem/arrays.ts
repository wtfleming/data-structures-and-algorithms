// Given an array of integers, return a a new array such that each element at index i pf the new array
// is the product of all the numbers in the original array except the one at i
export function getProductOfAllOtherElements(arr: number[]) {
  const totalProduct = arr.reduce((acc, currentVal) => acc * currentVal);
  return arr.map(x => totalProduct / x);
}

// Same as above, but without using division
export function getProductOfAllOtherElementsNoDivision(arr: number[]) {
  const prefixProducts: number[] = [];
  arr.forEach(num => {
    if (prefixProducts.length > 0) {
      prefixProducts.push(prefixProducts[prefixProducts.length - 1] * num);
    } else {
      prefixProducts.push(num);
    }
  });

  // JS array.reverse() reverses in place, so create a new array instead
  const reversedArray = [...arr].reverse();
  const suffixProducts: number[] = [];
  reversedArray.forEach(num => {
    if (suffixProducts.length > 0) {
      suffixProducts.push(suffixProducts[suffixProducts.length - 1] * num);
    } else {
      suffixProducts.push(num);
    }
  });

  suffixProducts.reverse();

  const result: number[] = [];

  arr.forEach((_val, idx) => {
    if (idx === 0) {
      result.push(suffixProducts[idx + 1]);
    } else if (idx === arr.length - 1) {
      result.push(prefixProducts[idx - 1]);
    } else {
      result.push(suffixProducts[idx + 1] * prefixProducts[idx - 1]);
    }
  });

  return result;
}
