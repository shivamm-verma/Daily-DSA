# Minimum Spanning Tree (MST) — Prim's and Kruskal's Algorithm

## Problem Statement
Given a connected, undirected, weighted graph, find the **Minimum Spanning Tree (MST)**.  
The MST is a subset of edges that:
1. Connects all vertices together.
2. Has no cycles.
3. Has the minimum possible total edge weight.

You need to implement the solution using:
- **Prim’s Algorithm**
- **Kruskal’s Algorithm**

---


### Understanding the Problem
- We have a graph with vertices `V` and edges `E`.
- We want the set of edges with minimum total weight such that all vertices are connected.
- We must ensure **no cycles** are formed.

---

### Choice of Algorithms
1. **Prim’s Algorithm**
   - Builds MST by **starting from a vertex** and adding the smallest edge connecting a visited vertex to an unvisited vertex.
   - Best for **dense graphs** with adjacency matrix representation.

2. **Kruskal’s Algorithm**
   - Builds MST by sorting all edges and adding them **if they don’t form a cycle** (Union-Find used for cycle detection).
   - Best for **sparse graphs** with edge list representation.

---



## Complexity Analysis

| Algorithm | Time Complexity | Space Complexity | Best Use Case |
|-----------|----------------|------------------|---------------|
| **Prim’s (Adj Matrix)** | O(V²) | O(V) | Dense graphs |
| **Prim’s (Adj List + Min Heap)** | O(E log V) | O(V + E) | Large sparse graphs |
| **Kruskal’s** | O(E log E) | O(V) | Sparse graphs |

---

# Minimum Spanning Tree – Prim's & Kruskal's (Adjacency List & Matrix)

---

## 1. Prim's Algorithm – Adjacency List

### Problem Statement
Given a connected, undirected, weighted graph represented as an adjacency list, find the Minimum Spanning Tree (MST) that connects all vertices with the minimum possible total edge weight.

### Algorithm Explanation
1. Choose any starting vertex (key = 0, all others = ∞).
2. Use a **min-priority queue** to select the vertex with the smallest key not in the MST.
3. Add it to the MST set.
4. For all adjacent vertices, if the edge weight is smaller than their current key, update the key and store the parent.
5. Repeat until all vertices are included in MST.

### Time Complexity
- **Using Min-Heap:** O(E log V)
- Space Complexity: O(V + E)

### Test Case
```
Vertices: 5
Edges:
(0,1,2), (0,3,6), (1,2,3), (1,3,8), (1,4,5), (2,4,7), (3,4,9)

Expected MST:
(0,1,2), (1,2,3), (1,4,5), (0,3,6)
```



### Conclusion
Efficient for **sparse graphs** since it only processes edges adjacent to the current MST.

---

## 2. Prim's Algorithm – Adjacency Matrix

### Problem Statement
Same as above, but the graph is represented as an **adjacency matrix**.

### Algorithm Explanation
1. Initialize all keys = ∞, except the starting vertex (key = 0).
2. Find the vertex with the minimum key not yet in MST (linear scan of vertices).
3. Add it to the MST set.
4. Update the keys of all vertices adjacent to it by checking the matrix.
5. Repeat until MST includes all vertices.

### Time Complexity
- **Without Heap:** O(V²)
- Space Complexity: O(V²)

### Test Case
```
Vertices: 4
Matrix:
0 10 6 5
10 0 0 15
6 0 0 4
5 15 4 0

Expected MST:
(0,3,5), (3,2,4), (0,1,10)

```
### Conclusion
Better for **dense graphs**; simpler to implement but slower for sparse graphs.

---

## 3. Kruskal's Algorithm – Adjacency List

### Problem Statement
Given a connected, undirected, weighted graph (adjacency list), find the MST.

### Algorithm Explanation
1. Extract all edges from the adjacency list.
2. Sort edges in ascending order by weight.
3. Initialize a **Disjoint Set Union (DSU)**.
4. Iterate over sorted edges:
   - If the current edge connects two different sets, include it in the MST.
   - Otherwise, skip it (to avoid cycles).
5. Stop when MST has (V - 1) edges.

### Time Complexity
- Sorting: O(E log E)
- DSU operations: ~O(E α(V))

### Test Case
```
Vertices: 4
Edges:
(0,1,10), (0,2,6), (0,3,5), (2,3,4)

Expected MST:
(2,3,4), (0,3,5), (0,1,10)
```
### Conclusion
Excellent for **sparse graphs**; DSU ensures cycle prevention with minimal overhead.

---

## 4. Kruskal's Algorithm – Adjacency Matrix

### Problem Statement
Same as above, but graph is represented as an adjacency matrix.

### Algorithm Explanation
1. Extract all edges from the matrix (skip duplicates since graph is undirected).
2. Sort the edges by weight.
3. Use DSU to add edges to MST without forming cycles.
4. Continue until MST has (V - 1) edges.

### Time Complexity
- Extract edges: O(V²)
- Sort edges: O(E log E) (E ≈ V² for dense graphs)
- DSU ops: ~O(E α(V))

### Test Case
```
Vertices: 4
Matrix:
0 10 6 5
10 0 0 15
6 0 0 4
5 15 4 0

Expected MST:
(2,3,4), (0,3,5), (0,1,10)
```


### Conclusion
Good for **dense graphs**, but has overhead of extracting edges from the matrix.
If you want, I can now append visual dry-runs for each algorithm showing the step-by-step edge selections and MST formation so it’s even clearer. That would make it perfect for revision notes.







