
---

# 📂 File 2: `remove_nth_node_from_end.md`

```markdown
# Remove Nth Node from the End of List (LeetCode 19)

## Description
Given the head of a linked list, remove the n-th node from the end of the list and return its head.

---

## Constraints
- Number of nodes: `[1, 30]`
- `0 <= Node.val <= 100`
- `1 <= n <= length of list`

---

## Test Cases
```text
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

Input: head = [1], n = 1
Output: []

Input: head = [1,2], n = 1
Output: [1]

## Tips
Tips to Identify Pattern

“Nth from end” → Two pointers trick.

Move fast pointer n steps ahead.

Then move both fast and slow until fast hits null.

Delete slow.next.