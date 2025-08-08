# 🏙️ Find the City With the Smallest Number of Neighbors at a Threshold Distance

---

## 🧾 Problem Statement

There are `n` cities numbered from `0` to `n-1`. Given an array of `edges` where each edge is represented as `(u, v, weight)` meaning there is a bidirectional road between city `u` and city `v` with distance `weight`, and a `distanceThreshold`.

You need to find the **city with the smallest number of reachable cities** such that the distance from the city to the other city is at most `distanceThreshold`.

In case of a tie, return the **city with the greatest number**.

---

## 🧠 Example

### Input:
n = 4  
edges = [
  (0, 1, 3),
  (1, 2, 1),
  (1, 3, 4),
  (2, 3, 1)
]
distanceThreshold = 4
Output: 3
### 🧩 Approach
* Use Floyd-Warshall Algorithm or Dijkstra’s Algorithm from each city.

* Compute shortest distances between all pairs.

* Count how many cities are reachable within the distanceThreshold.

* Track the city with the minimum reachable count and maximum index in case of a tie.

### 🛠️ Algorithm (Floyd-Warshall)
* Initialize a distance matrix with INT_MAX for all city pairs.

* Set distance to self as 0.

* Update direct edges.

* Run triple loop to compute all-pairs shortest paths.

* Count neighbors reachable under the threshold for each city.

* Return the city with the minimum count and highest index.

### 📈 Time Complexity
> Floyd-Warshall:

    O(n^3) — for computing all-pairs shortest path

    Dijkstra (Optimized):

O(n * (V + E) * log V) — Dijkstra from each node with min-heap

### 🧠 Space Complexity
 > O(n^2) for the distance matrix

### 📌 Topics Covered
-Graphs
-Shortest Paths
-Floyd-Warshall Algorithm
-Dijkstra’s Algorithm
