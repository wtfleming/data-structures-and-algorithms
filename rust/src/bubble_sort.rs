pub fn bubble_sort<T>(vector: &mut [T])
where
    T: Ord,
{
    // Empty vectors and those with length 1 are already sorted
    if vector.len() <= 1 {
        return;
    }

    let mut end_pos = vector.len() - 1;
    loop {
        let mut did_swap = false;
        for idx in 0..end_pos {
            if idx < vector.len() && vector[idx] > vector[idx + 1] {
                vector.swap(idx, idx + 1);
                did_swap = true;
            }
        }

        if !did_swap {
            break;
        }
        end_pos -= 1;
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_sorting_a_empty_vector() {
        let vector: &mut std::vec::Vec<i32> = &mut vec![];
        bubble_sort(vector);
        assert_eq!(vector, &mut vec![]);
    }

    #[test]
    fn test_sorting_a_vector_with_length_1() {
        let vector = &mut vec![22];
        bubble_sort(vector);
        assert_eq!(vector, &mut vec![22]);
    }

    #[test]
    fn test_sorting_a_vector_with_length_2() {
        let vector = &mut vec![22, 11];
        bubble_sort(vector);
        assert_eq!(vector, &mut vec![11, 22]);
    }

    #[test]
    fn test_sorting_a_vector_with_length_3() {
        let vector = &mut vec![55, 22, 11];
        bubble_sort(vector);
        assert_eq!(vector, &mut vec![11, 22, 55]);
    }

    #[quickcheck]
    fn test_sorting_quickcheck(mut xs: Vec<i32>) -> bool {
        let mut expected = xs.clone();
        expected.sort();

        bubble_sort(&mut xs);
        expected == xs
    }
}
