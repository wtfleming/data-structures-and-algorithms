pub fn selection_sort<T>(vector: &mut Vec<T>)
where
    T: PartialOrd,
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
            if value < &vector[smallest_index] {
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
    use rand::Rng;

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

    #[test]
    fn test_sorting_a_vector_with_random_values() {
        let len = 10;
        let mut vector = vec![0; len];

        let mut rng = rand::thread_rng();
        for i in &mut vector {
            *i = rng.gen::<i32>();
        }

        let mut expected = vector.clone();
        selection_sort(&mut vector);

        assert_ne!(vector, expected);
        expected.sort();
        assert_eq!(vector, expected);
    }
}
