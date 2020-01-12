// #[cfg(test)]
// #[macro_use]
// extern crate quickcheck;

#[cfg(test)]
extern crate quickcheck;
#[cfg(test)]
#[macro_use(quickcheck)]
extern crate quickcheck_macros;

pub mod binary_search;
pub mod bubble_sort;
pub mod insertion_sort;
pub mod selection_sort;
