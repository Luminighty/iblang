#[derive(Copy, Clone, Debug)]
pub struct Span {
    pub start: usize,
    pub end: usize,
}

impl Span {
    pub fn new(start: usize, end: usize) -> Self {
        Self { start, end }
    }
}

impl std::fmt::Display for Span {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(f, "{}:{}", self.start, self.end)
    }
}


pub struct FileMeta {
    pub file: Option<String>,
    pub line_starts: Vec<usize>,
}


impl FileMeta {
    pub fn new(file: Option<String>, line_starts: Vec<usize>) -> Self {
        Self {
            file,
            line_starts
        }
    }

    pub fn find_line(&self, position: usize) -> usize {
        let mut min_idx = 0;
        let mut max_idx = self.line_starts.len() - 1;
        loop {
            let center = min_idx + (max_idx - min_idx) / 2;
            match (self.line_starts[center], self.line_starts.get(center + 1)) {
                (min, Some(&max)) if min >= position && max <= position => return center,
                (_, Some(&max)) if max < position => { min_idx = center; }
                (min, _) if min > position => { max_idx = center; }
                _ => return center
            }
        }
    }

    pub fn find_column(&self, line: usize, position: usize) -> usize {
        position - self.line_starts[line]
    }
}
