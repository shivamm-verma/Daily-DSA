# 🧮 DSA QUESTION: Collecting Water

---

## 📝 Problem Statement

You are given the heights of `N` buildings. All the buildings are of width `1` and are adjacent to each other with no empty space in between. Assume that it is raining heavily, and as such water will be accumulated on top of certain buildings. Your task is to find the total amount of water accumulated.

---

## 💡 Example

**Input:**  
`heights = [4, 1, 3, 3, 5, 4, 1, 1, 2, 3, 3, 7, 4, 5, 2, 1]`

**Output:**  
`22`

**Explanation:**  
- Water accumulated above buildings at indices **1 to 3** is **5** units (`3+1+1`).
- Water accumulated above buildings at indices **5 to 10** is **16** units (`1+4+4+3+2+2`).
- Water accumulated above the building at index **12** is **1** unit.
- Hence, the total accumulated water is `5 + 16 + 1 = 22`.


---

## ✅ Constraints

- `1 <= heights.length <= 10^5`
- `1 <= a[i] <= 1000`

---

## 🐢 Brute-Force Approach

### 💡 Idea

For each building, the amount of water it can hold is determined by the shorter of the two tallest buildings to its left and right. We can iterate through each building and, for each one, find these two maximum heights.

### 🔁 Steps

1.  Iterate through each building from the second to the second-to-last (`i` from 1 to `n-2`).
2.  For each building `i`, find the maximum height of all buildings to its left (`leftMax`).
3.  Similarly, find the maximum height of all buildings to its right (`rightMax`).
4.  The water level above building `i` is `min(leftMax, rightMax)`.
5.  If this water level is higher than the height of building `i`, the water trapped is `waterLevel - heights[i]`.
6.  Add this amount to a running total.

---

## ⚡ Optimal Approach: Two Pointers

### 🧠 Key Idea

Instead of re-calculating the left and right maximums for every building, we can find the trapped water in a single pass. We use two pointers, one at the `left` end and one at the `right` end, and move them inward.

- We track the max height seen so far from the left (`leftMax`) and the right (`rightMax`).
- At any step, the amount of water trapped is limited by the **shorter of the two max heights**.
- If the left wall is shorter than the right wall (`heights[left] < heights[right]`), we can safely calculate the water trapped at the `left` pointer's position, because we know a taller wall exists on the right. We then move the `left` pointer inward.
- We do the opposite if the right wall is shorter.

---

### 🔁 Steps

1.  Use two pointers: `left` starting at `0` and `right` starting at `n-1`.
2.  Track the maximum height seen from the left (`leftMax`) and from the right (`rightMax`).
3.  Loop while `left` is less than `right`.
4.  If `heights[left]` is smaller than `heights[right]`:
    - If `heights[left]` is a new `leftMax`, update it.
    - Otherwise, add the trapped water (`leftMax - heights[left]`) to the total.
    - Move `left` pointer to the right.
5.  Else (if `heights[right]` is smaller or equal):
    - Do the same for the `right` pointer and `rightMax`.
    - Move `right` pointer to the left.
6.  Once the pointers meet, return the total water.

---

## 📜 Pseudocode

```text
function collectingWater(heights):
    n = length of heights
    if n <= 2: return 0

    left = 0, right = n - 1
    leftMax = 0, rightMax = 0
    totalWater = 0

    while left < right:
        if heights[left] < heights[right]:
            if heights[left] >= leftMax:
                leftMax = heights[left]
            else:
                totalWater += leftMax - heights[left]
            increment left
        else:
            if heights[right] >= rightMax:
                rightMax = heights[right]
            else:
                totalWater += rightMax - heights[right]
            decrement right

    return totalWater
```

### ⏱️ Complexity

- **Time:** `O(n^2)` (Brute) and `O(n)` (Optimal).
- **Space:** `O(1)`.
