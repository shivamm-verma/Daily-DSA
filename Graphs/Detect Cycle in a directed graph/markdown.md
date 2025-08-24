# Detect Cycle in a Directed Graph

## Problem Title
**Detect Cycle in a Directed Graph**

## Problem Description
Given a directed graph with `n` vertices and `m` edges, determine whether the graph contains a cycle.  
- The graph is represented using adjacency lists.  
- If a cycle exists, return `true`; otherwise, return `false`.  

---

## Brute Force Approach
### Idea
- Perform DFS from each node, keeping track of visited nodes in the current path.  
- If you reach a node that is already in the current path, a cycle is detected.  
- This is essentially **DFS with recursion stack tracking**, but implemented by re-running DFS from every node.  

### Complexity
- **Time Complexity:** \(O(n \cdot (n+m))\)  
  - For each node, a DFS is launched which may traverse all edges.  
- **Space Complexity:** \(O(n)\)  
  - For recursion stack and visited tracking.  

---

## Optimal Approach 1: DFS with Recursion Stack
### Idea
- Use a single DFS traversal with two arrays:
  - `visited[]`: tracks if a node has been visited.  
  - `recStack[]`: tracks if a node is in the current recursion path.  
- If during DFS, you encounter a node that is already in the recursion stack, a cycle exists.  

### Complexity
- **Time Complexity:** \(O(n+m)\)  
  - Each node and edge is visited once.  
- **Space Complexity:** \(O(n)\)  
  - For visited array, recursion stack, and function call stack.  

---

## Optimal Approach 2: Kahn’s Algorithm (BFS / Topological Sort)
### Idea
- Compute the in-degree of all nodes.  
- Repeatedly remove nodes with in-degree 0 (topological order).  
- If after processing, some nodes are left unvisited, it means those nodes are part of a cycle.  

### Complexity
- **Time Complexity:** \(O(n+m)\)  
  - Each node and edge is processed once.  
- **Space Complexity:** \(O(n)\)  
  - For in-degree array and queue.  

---

## Summary
- **Brute Force:** Run DFS from every node → \(O(n \cdot (n+m))\).  
- **Optimal DFS:** Detect cycle with recursion stack → \(O(n+m)\).  
- **Optimal BFS (Kahn):** Detect cycle via topological sort → \(O(n+m)\).  
