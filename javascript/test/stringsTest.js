'use strict';

const expect = require('chai').expect;
const strings = require('../src/strings');

describe('Strings', function() {
  describe('isPermutation()', function() {
    it('test if two strings are permutations of each other', function() {
      expect(strings.isPermutation("", "")).to.be.true;
      expect(strings.isPermutation("abb", "bba")).to.be.true;
      expect(strings.isPermutation("abb", "aba")).to.be.false;
      expect(strings.isPermutation("abb", "abac")).to.be.false;
    });
  });


  describe('isPermutationWithMap()', function() {
    it('test if two strings are permutations of each other', function() {
      expect(strings.isPermutationWithMap("", "")).to.be.true;
      expect(strings.isPermutationWithMap("abb", "bba")).to.be.true;
      expect(strings.isPermutationWithMap("abb", "aba")).to.be.false;
      expect(strings.isPermutationWithMap("abb", "abac")).to.be.false;
    });
  });


  describe('isPalindromePermutation()', function() {
    it('test if a string is a permutation of a palindrome', function() {
      expect(strings.isPalindromePermutation("tact coa")).to.be.true; // 'taco cat', 'atco cta'
      expect(strings.isPalindromePermutation("tact coaxyz")).to.be.false;
    });
  });


});
