'use strict';

function reverse(arr) {
  if (arr.length === 0) return arr;
  return doReverse(arr);
}

function doReverse([head, ...tail], acc = []) {
  if (tail.length === 0) return [head, ...acc];
  return doReverse(tail, [head, ...acc]);
}

module.exports = {
  reverse: reverse
};
