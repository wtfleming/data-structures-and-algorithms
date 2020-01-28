// DoublyLinkedList backed by a vector.
// Using a vector makes ownership / borrow checker easier to work with
// but in this implementation removing nodes will not free memory in the
// underlying vector.
// It would make sense to periodically shrink the vector, either
// when the list becomes empty, or after x number of operations and live
// with the amortized cost of resizing, but I have not implemented any
// of that logic here.
//
// Note, use this instead in actual code:
// https://doc.rust-lang.org/std/collections/struct.LinkedList.html



pub struct DoublyLinkedList {
    head: Option<usize>,
    tail: Option<usize>,

    nodes: Vec<Node>
}

pub struct Node {
    previous: Option<usize>,
    next : Option<usize>,
    value: i32,
}


impl DoublyLinkedList {
    pub fn new() -> Self {
        DoublyLinkedList {
            head: None,
            tail: None,
            nodes: vec!()
        }
    }

    pub fn push_front(&mut self, x: i32) {
        match self.head {
            None => {
                // Empty list, so create a node
                self.nodes.push(Node { previous: None, next: None, value: x });
                self.head = Some(self.nodes.len() - 1);
                self.tail = Some(self.nodes.len() - 1);
            }
            Some(old_head_position) =>{
                let new_head = Node { previous: None, next: None, value: x };
                self.nodes.push(new_head);
                let new_head_position = self.nodes.len() - 1;

                self.nodes[new_head_position].next = Some(old_head_position);
                self.nodes[old_head_position].previous = Some(new_head_position);

                self.head = Some(new_head_position);
            }
        }
    }

    pub fn pop_front(&mut self) -> Option<i32> {
        match self.head {
            None => None,
            Some(n) => {
                // If we are removing from a list of length 1 it will become empty
                if self.head == self.tail {
                    self.tail = None;
                }
                let new_head = self.nodes[n].next;
                self.head = new_head;
                if self.head.is_some() {
                    // If we have a new head, it's previous should now be None
                    self.nodes[self.head.unwrap()].previous = None;
                }
                Some(self.nodes[n].value)
            }
        }
    }

    pub fn push_back(&mut self, x: i32) {
        match self.tail {
            None => {
                // Empty list, so create a node
                self.nodes.push(Node { previous: None, next: None, value: x });
                self.head = Some(self.nodes.len() - 1);
                self.tail = Some(self.nodes.len() - 1);
            }
            Some(old_tail_position) => {
                let new_tail = Node { previous: None, next: None, value: x };
                self.nodes.push(new_tail);
                let new_tail_position = self.nodes.len() - 1;

                self.nodes[new_tail_position].previous = Some(old_tail_position);
                self.nodes[old_tail_position].next = Some(new_tail_position);

                self.tail = Some(new_tail_position);
            }
        }
    }


    pub fn pop_back(&mut self) -> Option<i32> {
        match self.tail {
            None => None,
            Some(n) => {
                // If we are removing from a list of length 1 it will become empty
                if self.head == self.tail {
                    self.head = None;
                }
                let new_tail = self.nodes[n].previous;
                self.tail = new_tail;
                if self.tail.is_some() {
                    // If we have a new tail, it's next should now be None
                    self.nodes[self.tail.unwrap()].next = None;
                }
                Some(self.nodes[n].value)
            }
        }
    }

}

#[cfg(test)]
mod test {
    use super::DoublyLinkedList;

    #[test]
    fn basics() {
        let mut list = DoublyLinkedList::new();

        // Check empty list behaves right
        assert_eq!(list.pop_front(), None);

        list.push_front(11);
        assert_eq!(list.pop_front(), Some(11));
        assert_eq!(list.pop_front(), None);


        list.push_front(11);
        list.push_front(22);
        assert_eq!(list.pop_front(), Some(22));
        assert_eq!(list.pop_front(), Some(11));
        assert_eq!(list.pop_front(), None);

        list.push_front(11);
        list.push_front(22);
        assert_eq!(list.pop_back(), Some(11));
        assert_eq!(list.pop_back(), Some(22));
        assert_eq!(list.pop_back(), None);
        assert_eq!(list.pop_front(), None);

        list.push_front(11);
        list.push_front(22);
        list.push_back(33);
        list.push_back(44);
        assert_eq!(list.pop_front(), Some(22));
        assert_eq!(list.pop_front(), Some(11));
        assert_eq!(list.pop_front(), Some(33));
        assert_eq!(list.pop_front(), Some(44));
        assert_eq!(list.pop_back(), None);
        assert_eq!(list.pop_front(), None);


        list.push_front(11);
        list.push_front(22);
        list.push_back(33);
        list.push_back(44);
        assert_eq!(list.pop_back(), Some(44));
        assert_eq!(list.pop_back(), Some(33));
        assert_eq!(list.pop_back(), Some(11));
        assert_eq!(list.pop_back(), Some(22));
        assert_eq!(list.pop_back(), None);
        assert_eq!(list.pop_front(), None);
    }
}
