Here’s your **DSA Question** written in clean **Markdown (`.md`) format**, ready to use for documentation, GitHub, or notes:

---

```markdown
# 🏰 The Kingdom’s Gold Vault

---

## 📜 Problem

In the prosperous land of **AlgoLand**, there are `N` rooms connected by tunnels.  
Each room contains a certain amount of gold.  

The kingdom has decided to assign a **single guard** who can start in **any room** and move through **adjacent rooms** (connected by tunnels) **without revisiting** any room.  

The guard’s objective is to **maximize the total gold collected** during the journey.  

You are given:  
- An integer `N` — the number of rooms.  
- An array `gold[]` of length `N`, where `gold[i]` represents the amount of gold in room `i`.  
- A list of tunnels represented as pairs `[u, v]` meaning there is a tunnel between room `u` and room `v`.  

Return the **maximum gold** the guard can collect following the rules.  

If there are **no tunnels** (rooms are isolated), the answer is simply the **maximum gold value** among all rooms.

---

## 🧮 Examples

### Example 1
**Input:**
```

N = 5
gold = [2, 5, 7, 1, 3]
tunnels = [[0, 1], [1, 2], [2, 3], [3, 4]]

```

**Output:**  
```

18

```

**Explanation:**  
The optimal path is from `0 → 1 → 2 → 3 → 4`, collecting  
`2 + 5 + 7 + 1 + 3 = 18`.

---

### Example 2
**Input:**
```

N = 4
gold = [10, 20, 30, 40]
tunnels = [[0, 1], [2, 3]]

```

**Output:**  
```

50

```

**Explanation:**  
There are two separate vault systems:
- Vault 1: `0 ↔ 1` → total = `30`
- Vault 2: `2 ↔ 3` → total = `70`

The guard should choose the second group of rooms for maximum gold.

---

### Example 3
**Input:**
```

N = 3
gold = [5, 1, 2]
tunnels = []

```

**Output:**  
```

5

```

**Explanation:**  
No tunnels exist, so the guard can only pick one room — the richest one.

---

## 🧩 Simple / Beginner Approach — DFS on Each Component

1. Build an adjacency list for all tunnels.  
2. Initialize a `visited[]` array.  
3. For each unvisited node:
   - Run a DFS to explore all connected rooms.
   - Sum up the gold in that component.
4. Keep track of the **maximum gold sum** among all components.  

**Return:** the maximum collected gold.

**Time Complexity:** `O(N + E)`  
**Space Complexity:** `O(N)`

---

## ⚙️ Medium / Logic Approach — DFS with Path Sum Tracking

1. Represent rooms as nodes in a graph.  
2. Use DFS to explore all paths **without revisiting** any node.  
3. For each path, accumulate gold and backtrack to explore alternatives.  
4. Use memoization to avoid recomputing overlapping paths.  

**Idea:** Similar to finding the *maximum path sum* in a graph/tree.

**Time Complexity:** `O(N + E)`  
**Space Complexity:** `O(N)`

---

## 🚀 Hard / Optimized Approach — Dynamic Programming on Graph (Tree DP)

1. Treat the system of tunnels as a forest (set of connected components).  
2. For each component, run a **Tree DP** where:  
```

dp[node] = gold[node] + max(dp[child1], dp[child2], …)

```
3. Return the **maximum dp[node]** across all components.  

**Optimizations:**
- Avoid recomputation with memoization.  
- Skip already processed components.

**Time Complexity:** `O(N + E)`  
**Space Complexity:** `O(N)`

---

## 🧠 Topics Covered
- Graph Theory  
- Arrays  
- Depth First Search (DFS)  
- Dynamic Programming  
- Connected Components  

---
```

