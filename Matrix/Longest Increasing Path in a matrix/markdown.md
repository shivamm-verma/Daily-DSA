## Longest Increasing Path in Matrix — Approaches Explained

### Problem Statement
Given an `m x n` integers matrix, return the length of the longest increasing path. From each cell, you can either move in four directions: left, right, up, or down. You may NOT move diagonally or move outside the boundary (i.e., wrap-around is not allowed).

### 📘 Example

#### Input
```text
Matrix: 
[9, 9, 4]
[6, 6, 8]
[2, 1, 1]

Output: 4
```

#### Visual Diagram
```text
Matrix:           Longest Path:
9  9  4           9  9  4
6  6  8     →     6  6 [8]
2  1  1           2 [1] 1

Path: 1 → 6 → 9 → ? (multiple 9s)
Actual longest: 1 → 2 → 6 → 9 (length = 4)
```

---

### 1️⃣ Brute Force Approach (Simple DFS from Each Cell)

#### Idea
- Start DFS from every cell in the matrix.
- For each cell, explore all four directions recursively.
- Keep track of the maximum path length found.
- No memoization - recalculate paths multiple times.

#### Why Brute Force?
- Recalculates the same subproblems multiple times
- No optimization for overlapping paths
- High time complexity due to redundant calculations


#### Complexity
- Time: O(4^(m×n)) - exponential due to repeated calculations
- Space: O(m×n) - recursion stack depth

---

### 2️⃣ Better Approach (DFS with Memoization)

#### Idea
- Use DFS from each cell but store results in a memoization table (dp array).
- When visiting a cell, first check if we've already calculated the longest path from it.
- If yes, return the stored result; if no, calculate and store it.
- This eliminates redundant calculations.

#### Advantage
- **Memoization**: Each cell's result is calculated only once
- **Optimal Substructure**: Longest path from a cell depends on longest paths from its neighbors
- **Efficient**: Dramatically reduces time complexity

#### Implementation Details
```text
dp[i][j] = longest increasing path starting from cell (i,j)

For each cell (x,y):
1. If dp[x][y] already calculated, return it
2. Initialize max_length = 1 (cell itself)
3. Check all 4 directions
4. If neighbor > current_cell:
   max_length = max(max_length, 1 + dfs(neighbor))
5. Store and return dp[x][y] = max_length
```


#### Complexity
- Time: O(m×n) - each cell visited once
- Space: O(m×n) - dp table + recursion stack

---

### 3️⃣ Optimal Approach (Topological Sort + BFS)

#### Idea
- Model the problem as a Directed Acyclic Graph (DAG).
- Each cell is a node, edges exist from smaller to larger adjacent values.
- Use topological sort to process cells in the correct order.
- Calculate longest path using dynamic programming on the sorted graph.

#### Why Optimal for Large Inputs?
- **Iterative**: No recursion stack overflow risk
- **Systematic**: Processes cells in dependency order
- **Cache Friendly**: Better memory access patterns
- **Scalable**: More efficient for very large matrices

#### Implementation Approach
```text
1. Calculate in-degree for each cell
2. Start BFS from cells with in-degree 0
3. Process cells level by level
4. Update path lengths as we process
5. Return maximum path length found
```


#### Complexity
- Time: O(m×n) - each cell and edge processed once
- Space: O(m×n) - in-degree array + queue

---

### 🔍 Key Insights

#### Direction Arrays Technique
```cpp
int dx[4] = {0, 0, -1, 1};  // left, right, up, down
int dy[4] = {-1, 1, 0, 0};
```
This pattern efficiently handles 4-directional movement without repetitive code.

#### Memoization Pattern
```cpp
if(dp[x][y] != 0) {
    return dp[x][y];  // Already calculated
}
// Calculate result
dp[x][y] = result;
return result;
```

#### Boundary Checking
```cpp
if(nx >= 0 && nx < m && ny >= 0 && ny < n && matrix[nx][ny] > matrix[x][y])
```
Ensures we stay within bounds and maintain increasing order.

---

### 📊 Comparison Summary

| Approach | Time Complexity | Space Complexity | Pros | Cons |
|----------|----------------|------------------|------|------|
| **Brute Force** | O(4^(m×n)) | O(m×n) | Simple to understand | Exponential time, very slow |
| **DFS + Memoization** | O(m×n) | O(m×n) | Optimal time, easy to code | Uses recursion (stack overflow risk) |
| **Topological Sort** | O(m×n) | O(m×n) | No recursion, scalable | More complex implementation |

---

### 🚀 When to Use Each Approach

- **Small matrices (≤ 10×10)**: Any approach works
- **Medium matrices (≤ 300×300)**: DFS + Memoization 
- **Large matrices or stack-sensitive environments**: Topological Sort + BFS
- **Interview setting**: DFS + Memoization strikes the best balance of efficiency and simplicity

---
