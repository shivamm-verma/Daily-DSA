# Reverse a Doubly Linked List

This project provides a C++ implementation to reverse a doubly linked list.

## Problem Statement

Given a doubly linked list, reverse it and return the head of the reversed list.

## Approach

- Traverse the list and swap the `next` and `prev` pointers for each node.
- Update the head pointer to the new front of the list.

## Usage

1. Clone the repository or copy the code.
2. Compile the C++ file:
    ```bash
    g++ reverse_doubly_linked_list.cpp -o reverse
    ```
3. Run the executable:
    ```bash
    ./reverse
    ```

## Example

**Input:** `1 <-> 2 <-> 3 <-> 4`  
**Output:** `4 <-> 3 <-> 2 <-> 1`

## License

This project is licensed under the MIT License.