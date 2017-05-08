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

  nth(n) {
    let node = this.head;
    while (n > 0) {
      node = node.next;
      n--;
    }
    return node.data;
  }
}


module.exports.LinkedList = LinkedList;
