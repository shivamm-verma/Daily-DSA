
---

# 📂 File 3: `find_duplicate_number.md`

```markdown
# Find the Duplicate Number (LeetCode 287)

## Description
Given an array of `n + 1` integers where each integer is in the range `[1, n]`, return the duplicate number.  

You must solve the problem without modifying the array and using only constant extra space.

---

## Constraints
- `1 <= n <= 10^5`
- Array length = `n+1`
- Exactly one duplicate number exists.

---

## Test Cases
```text
Input: [1,3,4,2,2]
Output: 2

Input: [3,1,3,4,2]
Output: 3

## Tips 
Tips to Identify Pattern

Array behaves like a linked list (nums[i] points to next index).

Cycle detection (Floyd’s Algorithm) helps find the duplicate.

Two phases:

Find intersection point.

Reset one pointer to start and move both one step at a time until they meet.