#  Trapping Rain Water II

##  Problem Statement

Given an `m x n` integer matrix `heightMap` representing a 2D elevation map where each cell is the height of the terrain, compute the total volume of water it can trap **after raining**.

Water can only be trapped if it is **fully surrounded by taller terrain**. Water flows from the boundaries and cannot be trapped there.

---

###  Input

- A 2D list of integers: `heightMap[m][n]`  
  `1 <= m, n <= 200`
- Each `heightMap[i][j]` represents the **elevation** at that point (non-negative integer).

---

###  Output

- Return an **integer** indicating the total units of water trapped.