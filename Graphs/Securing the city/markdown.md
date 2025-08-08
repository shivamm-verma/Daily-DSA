## DSA Question: Secure the City With Laser Grids

## Problem
You are given an `m x n` grid representing a city. The grid contains three types of cells:
* `'B'`: A building that already has a laser.
* `'O'`: An obstacle that blocks laser beams.
* `'E'`: An empty cell that needs to be secured.

A laser at any building `'B'` secures its entire row and column up until the grid edge or the first obstacle it encounters. Your task is to determine the **minimum number of additional lasers** you must place in empty cells to ensure every empty cell is secured. Placing a new laser turns an `'E'` cell into a `'B'`.

If it's impossible to secure all empty cells, return `-1`. *(Hint: When would this happen?)*

## Examples

### Example 1:
**Input:**
`[[B, E, E],
 [E, O, E],
 [E, E, E]]`

**Output:** `1`

**Explanation:** The building at `(0,0)` secures the first row and first column. The empty cells at `(2,1)` and `(2,2)` are unprotected. Since they are connected, we can place a single new laser at `(2,2)` to secure them both.

### Example 2:
**Input:**
`[[E, O, E],
 [O, E, O],
 [E, O, E]]`

 **Output:** `3`

**Explanation:** There are no initial lasers. The three empty cells at `(0,0)`, `(1,1)`, and `(2,2)` are all isolated from each other by obstacles. Each one forms its own "unprotected region" and requires a separate laser.

### Example 3:
**Input:**
`[[B, O, E],
 [O, O, O],
 [E, O, E]]`

**Output:** `-1`

**Explanation:** The empty cell at `(2,2)` is completely surrounded by obstacles and grid edges. No laser beam, existing or new, can ever reach it. Therefore, it's impossible to secure all cells.

## Approach
The core idea is to identify all "regions" of unprotected empty cells. Each distinct, connected region requires exactly one new laser.

1.  **Pre-computation:** Create a `protected` grid of the same dimensions. Iterate through the original grid to find all existing buildings (`'B'`). For each building, trace its row and column, marking all reachable cells in the `protected` grid as `true` until you hit an obstacle or the edge.

2.  **Count Regions:** Initialize a `regions = 0` counter and a `visited` grid. Iterate through the original grid again.

3.  **Find Unprotected Cells:** If you find an empty cell (`'E'`) that is **not** `protected` and has **not** been `visited`:
    * This cell is the start of a new unprotected region, so increment `regions`.
    * Begin a traversal (like **BFS** or **DFS**) from this cell.
    * The traversal should explore all adjacent empty cells that are also unprotected, marking each one as `visited` along the way. This ensures you map out the entire connected region and don't count it again.

4.  **Handle Impossibility:** The "impossible" case from the traversal logic can be tricky. A simpler, separate check is more reliable: before starting, iterate through the grid to see if any empty cell is completely surrounded by obstacles/edges, making it unreachable. If so, return `-1` immediately.

5.  **Return Result:** The final value of `regions` is the minimum number of new lasers required.

##  Complexities
> **Time Complexity**
**O(m × n)** — Each cell is visited a constant number of times during the pre-computation, the main loop, and the BFS/DFS traversal.

> **Space Complexity**
**O(m × n)** — Required for the `protected` and `visited` grids.