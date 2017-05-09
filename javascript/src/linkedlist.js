'use strict';


// Singly linkedlist node
class SLLNode {
  constructor(data, next) {
    this.data = data;
    this.next = next;
  }
}


class LinkedList {
  constructor() {
    this.head = undefined;
  }

  addFront(data) {
    let node = new SLLNode(data, this.head);
    this.head = node;
  }

  addTail(data) {
    let node = new SLLNode(data, undefined);
    if (this.head == undefined) {
      // list is empty, just add the node to the start
      this.head = node;
      return;
    }

    let pos = this.head;
    while (pos.next != undefined) {
      pos = pos.next;
    }
    pos.next = node;
  }

  nth(n) {
    let node = this.head;
    while (n > 0) {
      node = node.next;
      n--;
    }
    return node.data;
  }

  deleteNodeByValue(val) {
    let node = this.head;

    if (node != undefined && node.data == val) {
      // Removing the head of the list
      this.head = node.next;
    }

    while (node != undefined) {
      if (node.next != undefined && node.next.data == val) {
        node.next = node.next.next;
        return;
      }

      node = node.next;
    }
  }


  containsValue(val) {
    let node = this.head;
    while (node != undefined) {
      if (node.data == val) {
        return true;
      }
      node = node.next;
    }
    return false;
  }

  length() {
    let l = 0;
    let node = this.head;
    while (node != undefined) {
      l++;
      node = node.next;
    }
    return l;
  }

  removeDuplicates() {
    // TODO could optimize to just one pass over the list by checking the set for membership
    // and deleting a dupe node then and there.

    if (this.head == undefined) return;

    let node = this.head;
    let set = new Set();

    while (node != undefined) {
      set.add(node.data);
      node = node.next;
    }

    this.head = undefined;

    for (let item of set) {
      this.addFront(item);
    }

  }

}


module.exports.LinkedList = LinkedList;
