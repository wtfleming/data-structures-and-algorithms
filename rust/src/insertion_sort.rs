pub fn insertion_sort<T>(values: &mut [T])
where
    T: Ord,
{
    for i in 0..values.len() {
        for j in (0..i).rev() {
            if values[j] >= values[j + 1] {
                values.swap(j, j + 1);
            } else {
                break;
            }
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_sorting_a_empty_vector() {
        let vector: &mut std::vec::Vec<i32> = &mut vec![];
        insertion_sort(vector);
        assert_eq!(vector, &mut vec![]);
    }

    #[test]
    fn test_sorting_a_vector_with_length_1() {
        let vector = &mut vec![22];
        insertion_sort(vector);
        assert_eq!(vector, &mut vec![22]);
    }

    #[test]
    fn test_sorting_a_vector_with_length_2() {
        let vector = &mut vec![22, 11];
        insertion_sort(vector);
        assert_eq!(vector, &mut vec![11, 22]);
    }

    #[test]
    fn test_sorting_a_vector_with_length_3() {
        let vector = &mut vec![55, 22, 11];
        insertion_sort(vector);
        assert_eq!(vector, &mut vec![11, 22, 55]);
    }

    #[quickcheck]
    fn test_sorting_quickcheck(mut xs: Vec<i32>) -> bool {
        let mut expected = xs.clone();
        expected.sort();

        insertion_sort(&mut xs);
        expected == xs
    }
}
