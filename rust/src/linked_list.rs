// Note, in actual code use this instead https://doc.rust-lang.org/std/collections/struct.LinkedList.html
// Also refer to https://rust-unofficial.github.io/too-many-lists/

pub struct LinkedList<T> {
    head: Option<Box<Node<T>>>,
    size: usize,
}

pub struct Node<T> {
    data: T,
    next: Option<Box<Node<T>>>,
}

impl<T> LinkedList<T> {
    pub fn new() -> Self {
        LinkedList {
            head: None,
            size: 0,
        }
    }

    /// Adds a new node containing the specified value at the start of the LinkedList
    pub fn push(&mut self, e: T) {
        let node = Node {
            data: e,
            next: self.head.take(),
        };
        self.head = Some(Box::new(node));
        self.size += 1;
    }

    /// Removes the node at the beginning of the LinkedList
    pub fn pop(&mut self) -> Option<T> {
        self.head.take().map(|node| {
            self.head = node.next;
            self.size -= 1;
            node.data
        })
    }

    pub fn peek(&self) -> Option<&T> {
        self.head.as_ref().map(|node| {
            &node.data
        })
    }

    pub fn peek_mut(&mut self) -> Option<&mut T> {
        self.head.as_mut().map(|node| {
            &mut node.data
        })
    }
}

impl<T> Drop for LinkedList<T> {
    fn drop(&mut self) {
        let mut cur_link = self.head.take();
        while let Some(mut boxed_node) = cur_link {
            cur_link = boxed_node.next.take();
        }
        self.size = 0;
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn an_empty_list_has_size_zero() {
        let list: LinkedList<u32> = LinkedList::new();
        assert_eq!(list.size, 0);
    }

    #[test]
    fn adding_an_element_increases_size() {
        let mut list = LinkedList::new();
        list.push(10);
        assert_eq!(list.size, 1);
    }

    #[test]
    fn adding_and_removing_elements() {
        let mut list = LinkedList::new();
        list.push(22);
        list.push(11);
        let value = list.pop();
        assert_eq!(list.size, 1);
        assert_eq!(value.unwrap(), 11);

        list.push(33);
        list.push(44);
        assert_eq!(list.size, 3);

        let value = list.pop();
        assert_eq!(list.size, 2);
        assert_eq!(value.unwrap(), 44);
    }

    #[test]
    fn peek() {
        let mut list = LinkedList::new();
        assert_eq!(list.peek(), None);
        assert_eq!(list.peek_mut(), None);
        list.push(1); list.push(2); list.push(3);

        assert_eq!(list.peek(), Some(&3));
        assert_eq!(list.peek_mut(), Some(&mut 3));

        list.peek_mut().map(|value| {
            *value = 42
        });

        assert_eq!(list.peek(), Some(&42));
        assert_eq!(list.pop(), Some(42));
    }
}
