## ✅ DSA Question: Largest Rectangle in Histogram

---

### 🧠 Problem  
Given an array of integers `heights` representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

**Examples:**  
- Input: `heights = [2,1,5,6,2,3]` → Output: `10`  
  
> ![Histogram Example](![alt text](image.png))

   Explanation: The above is a histogram where width of each bar is 1.
   The largest rectangle is shown in the red area, which has an area = 10 units.
  

---

## 🧭 Approaches

### 🔹 1. Brute Force (Time: O(n²))
- For each bar:
  - Expand to the left and right until a smaller bar is found.
  - Compute area with: `height[i] * (right - left + 1)`
- Slow for large inputs. Will likely cause TLE.

---

### 🔹 2. Better – Using Precomputed NSL/NSR Naively (Time: O(n²))
- Use two nested loops to compute:
  - NSL (Nearest Smaller to Left)
  - NSR (Nearest Smaller to Right)
- Avoids recalculating bounds repeatedly but still **O(n²)** in worst case.

---

### 🔹 3. Optimal – Two-Pass Monotonic Stack (Time: O(n))
- Use two **monotonic stacks**:
  - First pass to compute `NSR[i]` (Nearest Smaller to Right)
  - Second pass to compute `NSL[i]` (Nearest Smaller to Left)
  - For each bar, compute: area = heights[i] * (NSR[i] - NSL[i] - 1)



---

### 🔹 4. Optimal – One-Pass Monotonic Stack (Time: O(n))
- Traverse from left to right.
- Maintain a stack of increasing height indices.
- Whenever current height is smaller than top of stack:
- Pop and calculate area using popped height.
- Width = distance between current index and new top of stack.
- Handles everything in one pass with stack.

---

## ⏱️ Complexities

### Time Complexity
O(n) — Each bar is pushed and popped at most once.

### Space Complexity
O(n) — Stack is used to store indices.


### What's NSL/NSR (Concept Brief)

This approach improves on brute force by explicitly computing boundaries for each bar — how far left and right the current bar can extend to form the largest rectangle **while all bars are at least as tall as it**.

---

#### 🔍 Definitions:

- **NSL (Nearest Smaller to Left)**:  
  For a given index `i`, NSL is the index of the first bar to the **left of `i`** that has a **smaller height** than `heights[i]`.

- **NSR (Nearest Smaller to Right)**:  
  For index `i`, NSR is the index of the first bar to the **right of `i`** that has a **smaller height** than `heights[i]`.

These values define the horizontal bounds of the largest rectangle that can be built using `heights[i]` as the shortest bar.

---

#### 📘 Example:

```plaintext
heights = [2, 1, 5, 6, 2, 3]
                   ↑
                index = 2 → height = 5

Scan left:
- bar at index 1 is height 1 < 5 ⇒ NSL[2] = 1

Scan right:
- bar at index 4 is height 2 < 5 ⇒ NSR[2] = 4

Width = NSR - NSL - 1 = 4 - 1 - 1 = 2  
Area  = height * width = 5 * 2 = 10

🧾 Logic:
For every bar:

Loop leftward to find NSL.

Loop rightward to find NSR.

Compute area using: area = heights[i] * (NSR[i] - NSL[i] - 1)

