# Reverse a Doubly Linked List

## Problem Statement

Given a doubly linked list, reverse the list so that the last node becomes the head and all pointers are correctly updated.

## Example

**Input:**
```
1 <-> 2 <-> 3 <-> 4 <-> 5
```

**Output:**
```
5 <-> 4 <-> 3 <-> 2 <-> 1
```

## Approach

- Traverse the doubly linked list.
- For each node, swap its `next` and `prev` pointers.
- Keep track of the new head (the last node visited).
- Return the new head after traversal.

## Pseudocode

```
function reverseDLL(head):
    temp = head
    newHead = head
    while temp is not NULL:
        swap temp.next and temp.prev
        newHead = temp
        temp = temp.prev
    return newHead
```

## Time Complexity

- **O(N)**, where N is the number of nodes in the list (each node is visited once).

## Space Complexity

- **O(1)**, as the reversal is done in-place without extra data structures.
