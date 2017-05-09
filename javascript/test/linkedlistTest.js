'use strict';

const expect = require('chai').expect;
const LinkedList = require('../src/linkedlist').LinkedList;


describe('LinkedLists', function() {
  describe('nth()', function() {
    it('should return the value at the nth position in a list', function() {

      let list = new LinkedList();
      list.addFront(111);
      list.addFront(222);

      expect(list.nth(0)).to.eql(222);
      expect(list.nth(1)).to.eql(111);

    });
  });


  describe('addTail()', function() {
    it('should add nodes to the end of a list', function() {
      let list = new LinkedList();
      list.addFront(111);
      list.addFront(222);
      list.addTail(333);

      expect(list.nth(0)).to.eql(222);
      expect(list.nth(1)).to.eql(111);
      expect(list.nth(2)).to.eql(333);
    });
  });

  describe('deleteNodeByValue()', function() {
    it('should add delete a node by value', function() {
      let list = new LinkedList();
      list.addFront(111);
      list.addFront(222);
      list.addFront(333);
      expect(list.nth(0)).to.eql(333);
      expect(list.nth(1)).to.eql(222);

      list.deleteNodeByValue(222);

      expect(list.nth(0)).to.eql(333);
      expect(list.nth(1)).to.eql(111);


      list = new LinkedList();
      list.addFront(111);
      list.addFront(222);
      list.deleteNodeByValue(222);
      expect(list.nth(0)).to.eql(111);
    });
  });


  describe('containsValue()', function() {
    it('should return if a value is in a list', function() {
      let list = new LinkedList();
      list.addFront(111);
      list.addFront(222);

      expect(list.containsValue(111)).to.be.true;
      expect(list.containsValue(222)).to.be.true;
      expect(list.containsValue(333)).to.be.false;
    });
  });


  describe('length()', function() {
    it('should return the length of the list', function() {
      let list = new LinkedList();
      expect(list.length()).to.eql(0);
      list.addFront(111);
      expect(list.length()).to.eql(1);

      list.addFront(222);
      expect(list.length()).to.eql(2);

      list.deleteNodeByValue(222);
      expect(list.length()).to.eql(1);
    });
  });


  describe('removeDuplicates()', function() {
    it('should remove duplicates from an unsorted list', function() {
      let list = new LinkedList();
      list.addFront(111);
      list.addFront(222);
      list.addTail(333);
      list.addFront(222);

      expect(list.length()).to.eql(4);

      list.removeDuplicates();
      expect(list.length()).to.eql(3);
      expect(list.containsValue(111)).to.be.true;
      expect(list.containsValue(222)).to.be.true;
      expect(list.containsValue(333)).to.be.true;
    });
  });




});

