'use strict';

const _ = require('lodash');


function isPermutation(left, right) {
  // Sort the letters in the strings
  return left.split('').sort().join('') == right.split('').sort().join('');
}


// Returns a Map with the count of how many of each letter is in a string
function letterCount(s) {
  let letters = new Map();
  _.each(s, (l) => {
    let x = letters.get(l);
    if (x === undefined) {
      letters.set(l, 1);
    } else {
      letters.set(l, x + 1);
    }
  });
  return letters;
}


function isPermutationWithMap(left, right) {
  let lettersLeft = letterCount(left);
  let lettersRight = letterCount(right);
  return _.isEqual(lettersLeft,lettersRight);
}



// Check if a string is a permutation of a palindrome
function isPalindromePermutation(s) {
  let letterFrequencies = letterCount(s);

  // A string is a palindrome if there is an even number of all letters,
  // except potentially one letter with an odd count
  let numOddLetters = 0;
  letterFrequencies.forEach((value, key) => {
    if (key == ' ') return; // ignore spaces
    if (value % 2 == 0) return;
    numOddLetters++;
  });

  if (numOddLetters < 2) return true;

  return false;
}

module.exports = {
  isPermutation: isPermutation,
  isPermutationWithMap: isPermutationWithMap,
  isPalindromePermutation: isPalindromePermutation
};
