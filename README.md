# CFlow

CFlow is a command-line task and job management system written entirely in C.

The project is built around singly linked lists in order to
explore dynamic memory management, pointers, data structures and algorithms
at a low level.

## Features

- Singly linked list
- Insert at front
- Insert at back
- Insert at index
- Search
- Delete by value
- Delete by index
- Reverse
- Find middle
- Calculate length
- Memory cleanup
- Unit tests

## Build

```bash
make
```

## Run
```bash
./cflow
```

## Language

- C11
----------------

| Operation | Time | Extra Space |
|---|---:|---:|
| `node_create` | O(1) | O(1) |
| `push_front` | O(1) | O(1) |
| `push_back` | O(n) | O(1) |
| `find` | O(n) | O(1) |
| `length` | O(n) | O(1) |
| `insert_at` | O(n) | O(1) |
| `delete_value` | O(n) | O(1) |
| `delete_at` | O(n) | O(1) |
| `reverse` | O(n) | O(1) |
| `middle` | O(n) | O(1) |
| `print` | O(n) | O(1) |
| `free` | O(n) | O(1) |