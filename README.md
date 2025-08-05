# Data Structures & Algorithms in C — Personal Challenge

This repo is my from-scratch implementations of core data structures and algorithms in C. The purpose is skill-building: write the code myself, understand it deeply, and keep it small and testable.

## Rules & workflow

- **No copy-paste**: I don’t paste code from the internet or past projects.
- **No AI for solutions**: I can ask for feedback on structure, but not for code/derivations.
- **Allowed references**: textbooks, pseudocode I write myself, and videos that explain the ideas (not line-by-line code).
- **Focus now**: correct implementations I’m not documenting time/space complexity yet.

## Current layout
```
.
├── include/
│   ├── dlist.h
│   └── list.h
├── Makefile
├── notes/
├── src/
│   ├── dlist/dlist.c
│   └── list/list.c
└── tests/
    ├── dlist_test.c
    └── list_test.c
```

## Progress board
### Done 
- [x] Singly linked list
- [x] Doubly linked list

### In progress
- [ ] Dynamic array
- [ ] Stack (array-backed)
- [ ] Queue

## Definition of "done" per module
- Public header in `include/`
- Implementation in `src/<name>/`
- Minimal tests in `tests/` covering edge cases (`empty`, `1-element`, `large`, `error paths`)
