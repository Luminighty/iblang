pub struct FileMeta {
    pub file: Option<String>,
    pub line_starts: Vec<usize>,
}

pub struct FilePositionMeta {
    pub line_start: usize,
    pub line: usize,
    pub column: usize,
    pub position: usize,
}


impl FileMeta {
    pub fn new(file: Option<String>, line_starts: Vec<usize>) -> Self {
        Self {
            file,
            line_starts
        }
    }

    pub fn position_meta(&self, position: usize) -> FilePositionMeta {
        let line = self.find_line(position);
        let line_start = self.line_starts[line];
        let column = position - self.line_starts[line];
        FilePositionMeta {
            line_start,
            line,
            column,
            position
        }
    }

    fn find_line(&self, position: usize) -> usize {
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

    fn find_column(&self, line: usize, position: usize) -> usize {
        position - self.line_starts[line]
    }
}


impl FilePositionMeta {
    pub fn write_line_pointer(
        &self, 
        f: &mut dyn std::io::Write,
        filecontent: &str
    ) -> std::io::Result<()> {
        let line: String = filecontent.chars().skip(self.line_start).take_while(|c| *c != '\n').collect();
        let tabs = line.chars().filter(|c| *c == '\t').count();
        let width = self.column + (tabs * 3);
        write!(f, "{}", line.replace("\t", "    "))?;
        writeln!(f, "{:>width$}", '^', width = width)
    }
}

