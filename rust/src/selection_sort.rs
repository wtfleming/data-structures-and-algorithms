pub fn selection_sort<T>(vector: &mut [T])
where
    T: Ord,
{
    // Empty vectors and those with length 1 are already sorted
    if vector.len() <= 1 {
        return;
    }

    let mut start = 0;
    let end = vector.len() - 1;
    loop {
        if start == end {
            break;
        }

        let mut smallest_index = start;
        for (idx, value) in vector.iter().enumerate().skip(start) {
            if vector[smallest_index] > *value {
                smallest_index = idx;
            }
        }
        vector.swap(start, smallest_index);
        start += 1;
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_sorting_a_empty_vector() {
        let vector: &mut std::vec::Vec<i32> = &mut vec![];
        selection_sort(vector);
        assert_eq!(vector, &mut vec![]);
    }

    #[test]
    fn test_sorting_a_vector_with_length_1() {
        let vector = &mut vec![22];
        selection_sort(vector);
        assert_eq!(vector, &mut vec![22]);
    }

    #[test]
    fn test_sorting_a_vector_with_length_2() {
        let vector = &mut vec![22, 11];
        selection_sort(vector);
        assert_eq!(vector, &mut vec![11, 22]);
    }

    #[test]
    fn test_sorting_a_vector_with_length_3() {
        let vector = &mut vec![55, 22, 11];
        selection_sort(vector);
        assert_eq!(vector, &mut vec![11, 22, 55]);
    }

    #[quickcheck]
    fn test_sorting_quickcheck(mut xs: Vec<i32>) -> bool {
        let mut expected = xs.clone();
        expected.sort();

        selection_sort(&mut xs);
        expected == xs
    }
}
