# C++ STL: Vector vs Array vs List

## Vector 

- Dynamic-sized
- Contiguous elements
- Initialized on the heap

## Array

- Size must be known at compile-time (it's a template parameter)
- Contiguous elements
- Initialized on the stack if the class that contains it is instantiated on the stack
- More efficient than the vector as it is mostly a lightweight wrapper around a C-style array

## List

- C++ implementation of a doubly-linked list
- Non-contiguous elements
- Slow traversal, but constant insertion and deletion
- For a singly-linked list, use forward_list