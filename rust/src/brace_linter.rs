// Check that for every opening brace there is a closing one in the correct order
pub fn is_well_formed(data: &str) -> bool {
    let mut braces: Vec<&str> = vec![];

    for c in data.split("") {
        match c {
            "{" | "(" | "[" => {
                braces.push(c);
            }
            "}" => match braces.pop() {
                Some("{") => (),
                _ => return false,
            },
            ")" => match braces.pop() {
                Some("(") => (),
                _ => return false,
            },
            "]" => match braces.pop() {
                Some("[") => (),
                _ => return false,
            },
            _ => (),
        }
    }
    braces.is_empty()
}

#[cfg(test)]
mod test {
    use super::*;

    #[test]
    fn test_is_well_formed() {
        assert!(!is_well_formed("(let x = 2;"));
        assert!(!is_well_formed("let x = 2);"));
        assert!(!is_well_formed("(let x = [1, 2, 3)];"));

        assert!(is_well_formed("(let x = [1, 2, 3]);"));
    }
}
