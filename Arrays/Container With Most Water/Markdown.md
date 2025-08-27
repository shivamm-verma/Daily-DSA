# 🧮 DSA QUESTION: Container With Most Water

---

## 📝 Problem Statement
You are given an array of integers `height` representing the heights of vertical lines on the x-axis.  

- Each line is at position `i` (0-indexed) and has height `height[i]`.  
- Find two lines such that together with the x-axis they form a container, which holds the **maximum amount of water**.  
- You cannot tilt the container; the width is the distance between the two lines.  

Return the **maximum area** of water the container can store.

---

## 💡 Examples

**Input:**  
`height = [1,8,6,2,5,4,8,3,7]`  

**Output:**  
`49`  

**Explanation:**  
- The lines at indices `1` (height 8) and `8` (height 7) form the container with the maximum area:  
  `width = 8 - 1 = 7`, `height = min(8, 7) = 7`, `area = 7 * 7 = 49`.

**Input:**  
`height = [1,1]`  

**Output:**  
`1`  

---

## ✅ Constraints
- `2 <= height.length <= 10^5`  
- `0 <= height[i] <= 10^4`  

---

## 🐢 Approach (Two-Pointer Technique)

### 💡 Idea
Use two pointers — one at the start and one at the end of the array — and move them inward to find the maximum area:  

- Initialize `left = 0` and `right = height.length - 1`.  
- Compute the area formed by `height[left]` and `height[right]`.  
- Move the pointer pointing to the **shorter line** inward, because moving the taller line cannot increase the area.  
- Repeat until the pointers meet.  
- Keep track of the **maximum area** found.

---

### 🔁 Steps
1. Initialize `left = 0`, `right = height.length - 1`, `max = 0`.  
2. While `left < right`:  
    - Compute `area = (right - left) * min(height[left], height[right])`.  
    - Update `max = max(max, area)`.  
    - If `height[left] < height[right]`, increment `left`.  
    - Else, decrement `right`.  
3. Return `max`.

---

### 📜 Pseudocode (Matching Java Solution)
```text
function maxArea(height):
    left = 0
    right = length(height) - 1
    max = 0

    while left < right:
        area = (right - left) * min(height[left], height[right])
        max = max(max, area)

        if height[left] < height[right]:
            left += 1
        else:
            right -= 1

    return max

**⏱️ Complexities***

Time Complexity: O(n) — each pointer moves at most n steps.
Space Complexity: O(1) — only constant extra space used.

**🧪 Edge Cases**

Array of size 2 → returns min(height[0], height[1]).
Heights containing zeros → area can be zero.
Large arrays (up to 10^5 elements) handled efficiently with two pointers.