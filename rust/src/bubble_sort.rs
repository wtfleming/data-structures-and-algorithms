pub fn bubble_sort<T>(vector: &mut Vec<T>)
where
    T: PartialOrd,
{
    if vector.len() < 2 {
        return;
    }

    loop {
        let mut did_swap = false;
        for idx in 0..vector.len() - 1 {
            if idx < vector.len() && vector[idx] > vector[idx + 1] {
                vector.swap(idx, idx + 1);
                did_swap = true;
            }
        }

        if !did_swap {
            break;
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use rand::Rng;

    #[test]
    fn test_sorting_a_empty_vector() {
        let vector: &mut std::vec::Vec<u32> = &mut vec![];
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

    #[test]
    fn test_sorting_a_vector_with_random_values() {
        let len = 10;
        let mut vector = vec![0; len];

        let mut rng = rand::thread_rng();
        for i in &mut vector {
            *i = rng.gen::<i32>();
        }

        let mut expected = vector.clone();
        bubble_sort(&mut vector);

        assert_ne!(vector, expected);
        expected.sort();
        assert_eq!(vector, expected);
    }
}
