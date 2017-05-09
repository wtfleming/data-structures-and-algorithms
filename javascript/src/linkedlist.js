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
    let node = new SLLNode(data, this.head);
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
}


module.exports.LinkedList = LinkedList;
