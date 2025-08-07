# 142. 🔐 Secure the City With Laser Grids

## Problem Statement

You are given a `m x n` grid where:

- `'.'` represents an **empty cell**
- `'B'` represents a **building** (can be equipped with a laser)
- `'O'` represents an **obstacle** (blocks laser beams)

A laser from a building travels in **four directions** (up, down, left, right) and stops when it hits an **obstacle** or the **grid boundary**. It can protect every empty cell in its path.

Your task is to determine the **minimum number of additional laser-equipped buildings** required so that **every empty cell is protected**.

If it is **impossible** to protect all empty cells, return `-1`.

---

### Examples

**Input:**

4 4
.B..
....
.OBO
..B.

**Output:**

2


**Explanation:**  
We can equip lasers on the first and last buildings. Their beams will cover all empty cells in the grid.

---

### Constraints

- `1 ≤ m, n ≤ 100`
- Grid contains only the characters `'.'`, `'B'`, `'O'`

---

## Approaches

### 1. Naive Approach – Brute Force (O((m×n)³) Time, O(m×n) Space)

- Try every possible combination of buildings to equip with lasers.
- For each combination, simulate laser coverage and check if all empty cells are protected.
- Track the minimum number of lasers required.
- Too slow for large inputs — only for understanding and very small grids.

---

### 2. Greedy Set Cover (O(k×(m+n)) Time, O(k + mn) Space)

- Track all empty cells (`to_cover`) and all buildings (`candidates`).
- For each building, compute which empty cells it can cover via laser.
- Iteratively select the building that covers the **maximum number of yet-uncovered** empty cells.
- Subtract those cells from `to_cover`, increment the count.
- If no building can cover remaining cells, return `-1`.

---

### 3. Optimized Using Priority Queue or Sorted Set (Optional Variant)

- Same as Greedy, but optimize with a max-heap or ordered set to always pick the best building faster.
- Complexity remains similar but performs better in practice for dense grids.

---

## Topics Covered

- Greedy  
- Graphs  
- Matrix  
- BFS / DFS  
- Set Cover Problem  
- Simulation  
- Binary Search (optional variants)

---

## Status

- [x] Problem Statement written  
- [x] Input/Output designed  
- [x] Greedy approach implemented  
- [ ] Brute-force implementation optional  
- [ ] Priority queue optimization (optional)