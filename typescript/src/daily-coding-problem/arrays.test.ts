import * as arrays from './arrays';


test('getProductOfAllOtherElements()', () => {
  expect(arrays.getProductOfAllOtherElements([1, 2, 3, 4, 5])).toEqual([120, 60, 40, 30, 24]);
  expect(arrays.getProductOfAllOtherElements([3, 2, 1])).toEqual([2, 3, 6]);
});

test('getProductOfAllOtherElementsNoDivision()', () => {
  expect(arrays.getProductOfAllOtherElementsNoDivision([1, 2, 3, 4, 5])).toEqual([120, 60, 40, 30, 24]);
  expect(arrays.getProductOfAllOtherElementsNoDivision([3, 2, 1])).toEqual([2, 3, 6]);
});
