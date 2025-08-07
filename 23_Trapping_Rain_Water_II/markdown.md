# Trapping Rain Water II

## Problem Statement

Given an `m x n` integer matrix `heightMap` representing a 2D elevation map where each cell is the height of the terrain, compute the total volume of water it can trap **after raining**.

Water can only be trapped if it is **fully surrounded by taller terrain**. Water flows from the boundaries and cannot be trapped there.

---

### Input

- A 2D list of integers: `heightMap[m][n]`
  - `1 <= m, n <= 200`
  - Each `heightMap[i][j]` represents the **elevation** at that point (non-negative integer).

---

### Output

- Return an **integer** indicating the total units of water trapped.

---

## Approach

**Key Observation:**
The problem can be modeled as finding basins in a 2D map. The amount of water a cell can hold is determined by the height of the lowest "wall" that surrounds it. We can think of this as pouring water from the edges of the map and seeing where it gets trapped. The initial "water level" is defined by the heights of the cells on the boundary of the map.

This suggests an algorithm that starts from the boundaries and moves inwards, similar to Dijkstra's or Breadth-First Search. We use a **min-priority queue** to always explore from the lowest point on the current boundary (or "shoreline").

**Algorithm Steps:**
1.  **Initialization**:
    - Create a min-priority queue to store tuples of `(height, row, col)`.
    - Create a `visited` matrix of the same dimensions to avoid processing cells multiple times.
    - Add all cells on the four borders of `heightMap` to the priority queue and mark them as `visited`. These cells form our initial containing wall.

2.  **Processing Loop**:
    - Initialize `total_water = 0`.
    - While the priority queue is not empty:
        - Pop the cell `(h, r, c)` with the minimum height from the queue. This `h` is the lowest point on our current "shoreline" and acts as the current water level for any adjacent, lower cells.
        - Explore the four neighbors (`up`, `down`, `left`, `right`) of the popped cell `(r, c)`.
        - For each `neighbor(nr, nc)`:
            - If the neighbor is within bounds and has not been visited:
                - Mark the neighbor as `visited`.
                - Calculate the trapped water at the neighbor's location. The water can fill up to the height `h` of the wall we just came from. So, trapped water is `max(0, h - heightMap[nr][nc])`. Add this amount to `total_water`.
                - The neighbor now becomes part of the new, inner "shoreline". The height of this new wall segment is its own height, but it cannot be lower than the wall `h` that allowed water to reach it. Therefore, add the neighbor to the priority queue with an effective height of `max(h, heightMap[nr][nc])`.

3.  **Result**:
    - After the loop finishes, `total_water` will hold the total volume of trapped water.

---

# ⚙️ Complexity
 >Time: $O(m.n.log(m.n))$ - Each grid cell is processed once, with priority queue operations taking logarithmic time.

 >Space: $O(m.n)$ - The `visited` matrix and the priority queue can store up to all $m \times n$ cells.