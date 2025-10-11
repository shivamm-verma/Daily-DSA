# Reverse Linked List (LeetCode 206)

## Description
Given the head of a singly linked list, reverse the list, and return its head.  
This must be done **in-place without extra space**.

---

## Constraints
- Number of nodes: `[0, 5000]`
- `-5000 <= Node.val <= 5000`

---

## Test Cases
```text
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]

Input: head = [1,2]
Output: [2,1]

Input: head = []
Output: []

## Tips to Identify Pattern

Common Linked List Reversal trick.

Iterative: keep track of prev, curr, next.

Recursive: reverse rest, fix pointers.