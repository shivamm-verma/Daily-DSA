## ✅ DSA Question: Next Greater Element in Circular Array

---

### 🧠 Problem  
Given a circular array, find the Next Greater Element (NGE) for every element.

- The Next Greater Element of a number is the first greater number found when traversing the array forward.
- Since the array is circular, traversal wraps around to the start after the end.
- If no greater number exists for an element, return `-1` for that element.

**Examples:**  
- Input: `[1, 2, 1]` → Output: `[2, -1, 2]`  
- Input: `[5, 4, 3, 2, 1]` → Output: `[-1, 5, 5, 5, 5]`

---

## 🧭 Approach

1. Use a monotonic decreasing stack to store indices of elements whose NGE is not yet found.
2. Traverse the array twice (from `0` to `2*n - 1`) to simulate circularity.
3. For each element in the traversal:
   - While the stack is not empty and the current element is greater than the element at the top of the stack:
     - Pop the top index from the stack.
     - Assign the current element as the NGE for the popped index.
   - If in the first pass (`i < n`), push the current index onto the stack.

---

## 🔁 Generic Logic (Pseudocode)
```plaintext
function nextGreaterElements(nums):
    n = length(nums)
    result = array of size n filled with -1
    stack = empty stack

    for i from 0 to 2*n - 1:
        current = nums[i % n]
        while stack not empty AND nums[stack.top] < current:
            index = stack.pop()
            result[index] = current
        if i < n:
            stack.push(i)

    return result
```

## ⏱️ Complexities

> Time Complexity
O(n) — each element is pushed and popped at most once.

> Space Complexity
O(n) — stack stores indices of unresolved elements, and result array of size n.
