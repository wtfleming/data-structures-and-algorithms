pub fn binary_search<T>(vector: Vec<T>, value: T) -> Option<usize>
where
    T: PartialOrd,
{
    if vector.is_empty() {
        return None;
    }

    let mut lower_bound: usize = 0;
    let mut upper_bound = vector.len() - 1;
    while lower_bound <= upper_bound {
        let midpoint = (lower_bound + upper_bound) / 2;
        match &vector[midpoint] {
            value_at_midpoint if value_at_midpoint < &value => lower_bound = midpoint + 1,
            value_at_midpoint if value_at_midpoint > &value => {
                if midpoint == 0 {
                    // Protect against a potential subtract with overflow error since midpoint is a usize
                    // Without the check, this test would panic when we attempted to subtract 1 from 0:
                    // assert!(binary_search(vec![33, 44, 55], 12).is_none());
                    return None;
                }
                upper_bound = midpoint - 1;
            }
            value_at_midpoint if value_at_midpoint == &value => return Some(midpoint),
            _ => (),
        }
    }
    None
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn a_empty_vector_returns_none() {
        assert!(binary_search(vec![], 12).is_none());
    }

    #[test]
    fn a_vector_of_length_one_returns_none_if_not_present() {
        assert!(binary_search(vec![33], 12).is_none());
    }

    #[test]
    fn a_vector_of_length_one_returns_the_index_if_present() {
        assert_eq!(binary_search(vec![12], 12).unwrap(), 0);
    }

    #[test]
    fn a_vector_of_length_two_returns_none_if_not_present() {
        assert!(binary_search(vec![33, 44], 12).is_none());
    }

    #[test]
    fn a_vector_of_length_two_returns_the_index_if_present() {
        assert_eq!(binary_search(vec![12, 33], 12).unwrap(), 0);
    }

    #[test]
    fn a_vector_of_length_three_returns_none_if_not_present() {
        assert!(binary_search(vec![33, 44, 55], 12).is_none());
        //assert!(binary_search(vec![1, 2, 3], 12).is_none());
    }

    #[test]
    fn a_vector_of_length_three_returns_the_index_if_present() {
        assert_eq!(binary_search(vec![1, 12, 44], 12).unwrap(), 1);
    }

    #[test]
    fn misc_assertions() {
        assert_eq!(binary_search(vec![12, 33, 55], 12).unwrap(), 0);
        assert_eq!(binary_search(vec![1, 12, 44], 12).unwrap(), 1);
        assert_eq!(binary_search(vec![1, 2, 12], 12).unwrap(), 2);

        assert_eq!(binary_search(vec![1, 2, 12, 22], 12).unwrap(), 2);
        assert_eq!(binary_search(vec![1, 2, 3, 12], 12).unwrap(), 3);
    }
}
