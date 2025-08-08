# Dijkstra's Algorithm — Shortest Path in Weighted Graph

## 🧾 Problem Statement

Find the shortest path from a given source to all other vertices in a weighted graph using Dijkstra’s Algorithm.

---

## 🧠 Example

Input:
V = 5
Edges = [
(0, 1, 2),
(0, 2, 4),
(1, 2, 1),
(1, 3, 7),
(2, 4, 3),
(3, 4, 1)
]
Source = 0


Output:
[0, 2, 3, 9, 6]


---

## 🧩 Approach

- Use a **min-heap (priority queue)** to always expand the shortest known vertex.
- Maintain a distance array and update it as you find shorter paths.
- Dijkstra is a greedy algorithm suitable for **non-negative edge weights**.

---

## 📈 Time Complexity

O((V + E) * log V)


## 🧠 Space Complexity

O(V) for distance array and priority queue


---

## 📌 Topics Covered

- Graphs
- Greedy Algorithms
- Priority Queue
- Dijkstra’s Algorithm

