'use strict';

const expect = require('chai').expect;
const arrays = require('../src/arrays');

describe('Arrays', function() {
  describe('reverse()', function() {
    it('should reverse arrays', function() {
      expect(arrays.reverse([1,2,3])).to.eql([3,2,1]);
      expect(arrays.reverse([])).to.eql([]);
    });
  });
});
