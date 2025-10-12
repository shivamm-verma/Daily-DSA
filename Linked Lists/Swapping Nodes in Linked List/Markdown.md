# Swapping Nodes in Linked List

### Description
You are given the head of a linked list, and an integer k.

Return the head of the linked list after swapping the values of the kth node from the beginning and the kth node from the end (the list is 1-indexed).

**Example:**  
Input: `1 -> 2 -> 3 -> 4 -> 5`  
Output: `1 -> 4 -> 3 -> 2 -> 5`

---

## Approach 1: Brute-Force

**Concept:**

- Traverse the entire linked list and store the values in an array.  
- Then using indexing of the array change the elements
- Now convert the array to Linked list

**Complexity:**

- Time: `O(N)`  
- Space: `O(N)`

---

## Approach 2: Optimal (Two-Pointer + Reverse Second Half)

**Concept:**

- Use two pointers (`slow` and `fast`) to find the middle of the linked list.  
- Reached at the middle of the list 
- Traverse k times and interchange the values.

**Complexity:**

- Time: `O(N)`  
- Space: `O(1)` (in-place reversal)
