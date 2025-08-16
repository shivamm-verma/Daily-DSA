# ✅ DSA Question: Detect Cycle in an Undirected Graph (DFS)

## 🧠 Problem
Given an **undirected graph**, determine if it contains at least **one cycle**.

A cycle in a graph means you can start from a node, follow a sequence of edges, and come back to the same node **without reusing an edge**.

### Example 1
**Input:**
V = 4, E = 3
Edges: 0-1, 1-2, 2-0

**Output:**
true (Cycle exists)



### Example 2
**Input:**
V = 4, E = 2
Edges: 0-1, 2-3


**Output:**
false (No cycle)



---

## 🧭 Approach
We will use **Depth-First Search (DFS)** with the following idea:

1. **Visited tracking**  
   Keep an array to mark visited nodes.

2. **Parent tracking**  
   While doing DFS, remember which node you came from (parent).  
   - If you visit a node that is already visited **and** it’s **not the parent**, it means we found a cycle.

3. Repeat DFS for all unvisited nodes (to handle disconnected graphs).

---


---

## 📈 Time Complexity

O(V + E) — We visit every vertex and edge once.

## 🧠 Space Complexity

O(V) — For visited array and recursion stack.

---

## 📌 Topics Covered

- Graphs
- DFS Traversal
- Cycle Detection
- Undirected Graphs


## 🔁 Generic Logic (Pseudocode)
```pseudo
function hasCycle(graph, V):
    visited = [false] * V
    
    for each vertex v in [0...V-1]:
        if not visited[v]:
            if dfs(v, -1, visited, graph):
                return true
    return false

function dfs(node, parent, visited, graph):
    visited[node] = true
    
    for neighbor in graph[node]:
        if not visited[neighbor]:
            if dfs(neighbor, node, visited, graph):
                return true
        else if neighbor != parent:
            return true  // Found cycle
    return false



