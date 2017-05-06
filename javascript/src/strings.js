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


function isOneReplacementAway(left, right) {
  let numReplacements = 0;

  for (let i=0; i < left.length; i++) {
    let l = left.charAt(i);
    let r = right.charAt(i);
    if (l != r) {
      numReplacements++;
    }

    if (numReplacements > 1) return false;
  }
  return true;
}

function isOneInsertionOrRemovalAway(left, right) {
  let shorter, longer;

  if (left.length > right.length) {
    shorter = right;
    longer = left;
  } else {
    shorter = left;
    longer = right;
  }

  let numChanges = 0;
  let longerOffset = 0;

  for (let i=0; i < shorter.length; i++) {
    if (shorter.charAt(i) == longer.charAt(i + longerOffset)) continue;

    numChanges++;
    longerOffset++;

    if (numChanges > 1) return false;
  }


  return true;
}


// 3 types of edits on strings, insert a character, remove a character, or replace a character
// Determine if two strings ate one or zero edits from each other
function isOneEditAway(left, right) {
  if (left == right) return true;
  if (Math.abs(left.length - right.length) > 1) return false; // we know there are at least 2 edits on this string
  if (left.length == right.length) return isOneReplacementAway(left, right);



  return isOneInsertionOrRemovalAway(left, right);
}

module.exports = {
  isPermutation: isPermutation,
  isPermutationWithMap: isPermutationWithMap,
  isPalindromePermutation: isPalindromePermutation,
  isOneEditAway: isOneEditAway
};
