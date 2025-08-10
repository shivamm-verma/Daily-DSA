## Problem

You are driving from a starting point to a destination target miles away. Your car initially has startFuel liters of fuel. Along the way, there are gas stations; each station i is at distance stations[i][0] from the start and has stations[i][1] liters of fuel available.

When you reach a station, you may stop and take all (or part) of its fuel. Fuel consumption is 1 liter per mile. What is the minimum number of refueling stops needed to reach the destination? If it's impossible, return -1.

```
Example 1

Input: target = 100, startFuel = 10, stations = [[10,60],[20,30],[30,30],[60,40]]
Output: 2
Explanation: Stop at station at 10 (fuel becomes 70), drive to 60, stop (fuel becomes 110), reach 100.

```

## Approach (Greedy with Max-Heap)

Drive forward, and whenever you cannot reach the next station or the target, pick the previously passed station with the largest fuel (max-heap) to refuel. Each time you pop from heap, you increase stops by 1 and increase current fuel.

We iterate over stations (plus a final sentinel at target), pushing reachable stations' fuel into a max-heap. When currentFuel is insufficient to reach the next station, pop from heap (largest fuel); if heap empty -> impossible.

## Code
### Java
```java
import java.util.*;
class Solution {
    public int minRefuelStops(int target, int startFuel, int[][] stations) {
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        int n = stations.length;
        int i = 0;
        int curr = startFuel;
        int stops = 0;
        while (curr < target) {
            while (i < n && stations[i][0] <= curr) {
                pq.offer(stations[i][1]);
                i++;
            }
            if (pq.isEmpty()) return -1;
            curr += pq.poll();
            stops++;
        }
        return stops;
    }
    public static void main(String[] args) {
        Solution s = new Solution();
        int[][] stations = {{10,60},{20,30},{30,30},{60,40}};
        System.out.println(s.minRefuelStops(100,10,stations)); // 2
    }
}

```

### Python 
```python
import heapq
class Solution:
    def minRefuelStops(self, target: int, startFuel: int, stations: list[list[int]]) -> int:
        max_heap = []  
        stations.append([target, 0])
        curr = startFuel
        stops = 0
        for pos, fuel in stations:
            while curr < pos:
                if not max_heap:
                    return -1
                curr += -heapq.heappop(max_heap)
                stops += 1
            heapq.heappush(max_heap, -fuel)
        return stops

if __name__ == '__main__':
    sol = Solution()
    print(sol.minRefuelStops(100, 10, [[10,60],[20,30],[30,30],[60,40]]))  # 2
```

### C++
```cpp
#include <bits/stdc++.h>
using namespace std;

int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
    priority_queue<int> pq;
    int i = 0, n = stations.size();
    long long curr = startFuel;
    int stops = 0;
    while (curr < target) {
        while (i < n && stations[i][0] <= curr) {
            pq.push(stations[i][1]);
            i++;
        }
        if (pq.empty()) return -1;
        curr += pq.top(); pq.pop();
        stops++;
    }
    return stops;
}

int main(){
    vector<vector<int>> stations = {{10,60},{20,30},{30,30},{60,40}};
    cout<<minRefuelStops(100,10,stations)<<"\n"; // 2
}
```

## Complexity

- Time: O(n log n) where n = number of stations (heap operations)

- Space: O(n)