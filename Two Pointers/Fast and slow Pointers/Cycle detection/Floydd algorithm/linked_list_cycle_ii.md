# Linked List Cycle II (LeetCode 142)

## Description
Given the head of a linked list, return the node where the cycle begins.  
If there is no cycle, return `null`.

---

## Constraints
- The number of nodes is in the range `[0, 10^4]`.
- `-10^5 <= Node.val <= 10^5`
- `pos` is the index where the tail connects to (or `-1` if no cycle).

---

## Test Cases
```text
Input: head = [3,2,0,-4], pos = 1
Output: node at index 1 (value = 2)

Input: head = [1,2], pos = 0
Output: node at index 0 (value = 1)

Input: head = [1], pos = -1
Output: null

## Tips to identify such pattern
Tips to Identify Pattern

Cycle-related → think Fast & Slow Pointers.

Step 1: Detect cycle with Floyd’s Algorithm.

Step 2: Reset one pointer to head, move both step by step until they meet → that’s the cycle start.