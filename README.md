# OSTEP Projects

This repository contains my solutions to the **Operating Systems: Three Easy Pieces (OSTEP)** projects.  
The projects are small utilities that help reinforce concepts in operating systems, C programming, and systems-level thinking.

Project questions are available at: [OSTEP Projects](https://github.com/remzi-arpacidusseau/ostep-projects/tree/master)

## Structure
The structure is identical to the questionnaire repo:

**General Topic → Specific Project**

## Completed Projects

#### Initial Utilities
- [`wcat`](./initial-utilities/wcat/wcat.c) – print the contents of a file
- [`wgrep`](./initial-utilities/wgrep/wgrep.c) – search for a string in a file or stdin
- [`wzip`](./initial-utilities/wzip/wzip.c) – basic run-length encoding
- [`wunzip`](./initial-utilities/wzip/wzip.c) – reversing wzip

More projects will be added as I progress through the book.

## Building
To compile any project:
```bash
gcc -o <binary_name> <source_file>.c
```

## Testing
Tests are availbe at the questionnaire repo. Binary file should be where the test.sh is.
