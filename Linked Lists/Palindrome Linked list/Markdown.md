# Palindrome Linked List

### Description
Given the head of a singly linked list, determine whether the list is a palindrome.  
A list is considered a palindrome if it reads the same backward as forward.

**Example:**  
Input: `1 -> 2 -> 2 -> 1`  
Output: `true`

---

## Approach 1: Brute-Force

**Concept:**

- Traverse the entire linked list and store the values in an array.  
- Use two-pointer technique to check whether the array forms a palindrome.  
- If all corresponding pairs match, the list is a palindrome.

**Complexity:**

- Time: `O(N)`  
- Space: `O(N)` (for the array)

---

## Approach 2: Optimal (Two-Pointer + Reverse Second Half)

**Concept:**

- Use two pointers (`slow` and `fast`) to find the middle of the linked list.  
- Reverse the second half of the list.  
- Compare nodes from the beginning and the reversed second half one by one.  
- If all values match, it’s a palindrome.

**Complexity:**

- Time: `O(N)`  
- Space: `O(1)` (in-place reversal)
