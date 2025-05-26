use super::Span;

pub struct FileMeta {
    pub file: Option<String>,
    pub line_starts: Vec<usize>,
}

#[derive(Debug)]
pub struct FilePositionMeta {
    pub line_start: usize,
    pub line: usize,
    pub column: usize,
    #[allow(dead_code)]
    pub position: usize,
    pub length: usize,
}


impl FileMeta {
    pub fn new(file: Option<String>, line_starts: Vec<usize>) -> Self {
        Self {
            file,
            line_starts
        }
    }

    pub fn span_meta(&self, span: &Span) -> FilePositionMeta {
        let mut meta = self.position_meta(span.start);
        meta.length = span.end - span.start;
        meta
    }

    pub fn position_meta(&self, position: usize) -> FilePositionMeta {
        let line = self.find_line(position);
        let line_start = self.line_starts[line];
        let column = position - self.line_starts[line];
        FilePositionMeta {
            length: 1,
            line_start,
            line,
            column,
            position
        }
    }

    fn find_line(&self, position: usize) -> usize {
        let mut min_idx = 0;
        let mut max_idx = self.line_starts.len() - 1;
        // println!("Position: {position}");
        loop {
            let center = min_idx + (max_idx - min_idx) / 2;
            // println!("{} {} {}", min_idx, center, max_idx);
            // println!("min: {} max: {:?}", self.line_starts[center], self.line_starts.get(center + 1));
            match (self.line_starts[center], self.line_starts.get(center + 1)) {
                (min, Some(&max)) if min >= position && max < position => return center,
                (_, Some(&max)) if max <= position => { min_idx = center; }
                (min, _) if min > position => { max_idx = center; }
                _ => return center
            }
        }
    }
}


impl FilePositionMeta {
    pub fn write_line_pointer(
        &self, 
        f: &mut dyn std::io::Write,
        filecontent: &str
    ) -> std::io::Result<()> {
        let padleft_len = (self.line.checked_ilog10().unwrap_or(0) + 2) as usize;
        let padleft = " ".repeat(padleft_len);

        let line: String = filecontent.chars().skip(self.line_start).take_while(|c| *c != '\n').collect();
        let tabs = line.chars().filter(|c| *c == '\t').count();
        let width = self.column + (tabs * 3 + 1);
        writeln!(f, "{padleft}| ")?;
        writeln!(f, "{} | {}", self.line + 1, line.replace("\t", "    "))?;
        write!(f, "{padleft}| {:>width$}", '^', width = width)?;
        for _ in 1..self.length {
            write!(f, "^")?;
        }
        writeln!(f)
    }
}

