'use strict';


function reverse([head, ...tail], acc = []) {
  if (head === undefined) return acc;
  if (tail.length === 0) return [head, ...acc];
  return reverse(tail, [head, ...acc]);
}

module.exports = {
  reverse: reverse
};
