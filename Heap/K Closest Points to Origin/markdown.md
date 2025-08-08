# K Closest Points to Origin

## Problem Statement
**LeetCode #973**

Given an array of points where `points[i] = [x_i, y_i]` represents a point on the X-Y plane and an integer `k`, return the `k` closest points to the origin `(0, 0)`.

The distance between two points on the X-Y plane is the Euclidean distance (but for comparison, squared distance can be used to avoid costly square roots):

$$
\text{distance} = \sqrt{x^2 + y^2}
$$
 
---
## Example

**Input:**  
points = [[3,3], [5,-1], [-2,4]]
k = 2

**Output:**  
[[3,3], [-2,4]]

**Explanation:**  
The squared distances to origin are:  
- (3,3) → \(3^2 + 3^2 = 18\)  
- (5,-1) → \(5^2 + (-1)^2 = 26\)  
- (-2,4) → \((-2)^2 + 4^2 = 20\)  

The two points with smallest distances are `[3,3]` and `[-2,4]`.

---
## 1. Brute Force Solution (Sorting All Points)

### Approach
- Calculate the squared distance for each point.
- Sort all points by their squared distance.
- Return the first `k` points after sorting.

### Time Complexity
- Sorting all points: **O(n log n)**, where `n` is the number of points.

### Space Complexity
- **O(n)** for storing the points and their distances.

### Code
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<int, vector<int>>> distPoints;
        for (int i = 0; i < points.size(); i++) {
            int x = points[i][0];
            int y = points[i][1];
            int dist = x * x + y * y; // squared distance
            distPoints.push_back({dist, points[i]});
        }
        // Sort points by distance
        sort(distPoints.begin(), distPoints.end());

        // Take first k points
        vector<vector<int>> result;
        for (int i = 0; i < k; i++) {
            result.push_back(distPoints[i].second);
        }
        return result;
    }
};

int main() {
    vector<vector<int>> points = {{3,3}, {5,-1}, {-2,4}};
    int k = 2;
    Solution sol;
    vector<vector<int>> ans = sol.kClosest(points, k);

    cout << "K Closest Points:";
    for (int i = 0; i < ans.size(); i++) {
        cout << "[" << ans[i][0] << "," << ans[i][1] << "]";
    }
    cout << endl;

    return 0;
}
````

---

## 2. Optimal Solution (Using Max Heap)

### Approach

* Use a max heap (priority queue) to store the closest `k` points seen so far.
* For each point:

  * Calculate squared distance.
  * Push it to the heap.
  * If heap size exceeds `k`, pop the farthest point.
* After processing all points, heap contains the `k` closest points.

### Time Complexity

* For each point, insertion/removal in heap takes **O(log k)**.
* Total: **O(n log k)**.

### Space Complexity

* **O(k)** for the heap.

### Code

```cpp
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> maxheap;
        for (int i = 0; i < points.size(); i++) {
            int x = points[i][0];
            int y = points[i][1];
            int dist = x * x + y * y;
            maxheap.push({dist, points[i]});
            if (maxheap.size() > k) {
                maxheap.pop();
            }
        }
        vector<vector<int>> result;
        while (!maxheap.empty()) {
            result.push_back(maxheap.top().second);
            maxheap.pop();
        }
        return result;
    }
};

int main() {
    vector<vector<int>> points = {{3,3}, {5,-1}, {-2,4}};
    int k = 2;
    Solution sol;
    vector<vector<int>> ans = sol.kClosest(points, k);

    cout << "K Closest Points:";
    for (int i = 0; i < ans.size(); i++) {
        cout << "[" << ans[i][0] << "," << ans[i][1] << "]";
    }
    cout << endl;

    return 0;
}
```

---

## Summary

| Solution           | Time Complexity | Space Complexity | Description                 |
| ------------------ | --------------- | ---------------- | --------------------------- |
| Brute Force (Sort) | O(n log n)      | O(n)             | Sort all points by distance |
| Optimal (Max Heap) | O(n log k)      | O(k)             | Maintain a heap of size `k` |

---

## References

* LeetCode Problem: [973. K Closest Points to Origin](https://leetcode.com/problems/k-closest-points-to-origin/)

---
