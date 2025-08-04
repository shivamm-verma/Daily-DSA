
## 🎒 Unbounded Knapsack Problem — Approaches Explained

## 📘 Problem Statement
Given two integer arrays `wt[]` and `val[]` representing weights and values of n items respectively, and an integer capacity representing a knapsack with limited capacity, determine the maximum total value that can be obtained with unlimited supply of each item.

You can include an item multiple times if it fits.

## 🧪 Example
Input:
    Weights (wt):  [1, 3, 4, 5]  
    Values (val):  [6, 1, 7, 7]  
    Knapsack Capacity: 8  
Output
    Maximum Value: 48  

## Explanation: 
    Choose item with weight 1 and value 6, eight times. (6×8 = 48)

## 1️⃣ Brute Force Recursive Approach (Without Memoization)
## 💡 Idea
* Try all combinations of including or excluding each item.

* At every index, you can:

* Take the item and stay at the same index (ind) (since unbounded).

* Not take the item and move to the previous index (ind - 1).

## ⚙️ Complexity
 >Time: O(2^n) (exponential)

 >Space: O(n) (recursive stack)

## 2️⃣ Top-Down DP (Memoization)
## 💡 Idea
* Add a memoization table `dp[ind][capacity]` to store results of overlapping subproblems.

* Reduces redundant calls.

## ⚙️ Complexity
 >Time: O(n × capacity)

 >Space: O(n × capacity) (for memo table)

## 3️⃣ Bottom-Up DP (Tabulation)
## 💡 Idea
* Use a 2D dp table where `dp[i][w]` is the maximum value for i items and capacity w.

* Start filling the table from base cases.

## ⚙️ Complexity
 >Time: O(n × capacity)

 >Space: O(n × capacity)

## 4️⃣ Space Optimized DP (1D Array)
## 💡 Idea
* Use a 1D array `dp[w]` where each entry keeps track of the max value at that capacity.

* Only one row is required because `dp[i][w]` only depends on `dp[i][w - wt[i]]`.

## ⚙️ Complexity
 >Time: O(n × capacity)

 >Space: O(capacity)


---
## Code 
Optimal
### Java
```java
import java.util.*;

class java code {
    private static int knapsack(int[] wt,int[] val,int capacity,int n) {
        int[][] dp=new int[n][capacity+1];
        for(int w=0;w<=capacity;w++) dp[0][w]=((int)(w/wt[0]))*val[0];

        for(int i=1;i<n;i++) {
            for(int w=0;w<=capacity;w++) {
                int notTake=dp[i-1][w];
                int take=Integer.MIN_VALUE;
                if(wt[i]<=w) take=val[i]+dp[i][w-wt[i]];
                dp[i][w]=Math.max(notTake, take);
            }
        }
        return dp[n-1][capacity];
    }
    public static void main(String[] args) {
        int[] val={6,1,7,7};
        int[] wt={1,3,4,5};
        int capacity=8;
        System.out.println(knapsack(wt,val,capacity,wt.length));
    }    
}

```

### Python 
```python
def knapsack(wt, val, capacity, n):
    dp = [[0 for _ in range(capacity + 1)] for _ in range(n)]

    for w in range(capacity + 1):
        dp[0][w] = (w // wt[0]) * val[0]

    for i in range(1, n):
        for w in range(capacity + 1):
            not_take = dp[i - 1][w]
            take = float('-inf')
            if wt[i] <= w:
                take = val[i] + dp[i][w - wt[i]]
            dp[i][w] = max(not_take, take)

    return dp[n - 1][capacity]

if __name__ == "__main__":
    val = [6, 1, 7, 7]
    wt = [1, 3, 4, 5]
    capacity = 8
    print(knapsack(wt, val, capacity, len(wt)))

```

### C++
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int knapsack(vector<int>& wt, vector<int>& val, int capacity, int n) {
    vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));

    for (int w = 0; w <= capacity; w++) {
        dp[0][w] = (w / wt[0]) * val[0];
    }

    for (int i = 1; i < n; i++) {
        for (int w = 0; w <= capacity; w++) {
            int notTake = dp[i - 1][w];
            int take = INT_MIN;
            if (wt[i] <= w)
                take = val[i] + dp[i][w - wt[i]];
            dp[i][w] = max(notTake, take);
        }
    }

    return dp[n - 1][capacity];
}

int main() {
    vector<int> val = {6, 1, 7, 7};
    vector<int> wt = {1, 3, 4, 5};
    int capacity = 8;
    cout << knapsack(wt, val, capacity, wt.size()) << endl;
    return 0;
}
```

---
Space Optimize

### Java
```java
import java.util.*;

class java code {
    private static int knapsack(int[] wt,int[] val,int capacity,int n) {
        int[] prev=new int[capacity+1];
        for(int w=0;w<=capacity;w++) prev[w]=((int)(w/wt[0]))*val[0];

        for(int i=1;i<n;i++) {
            for(int w=0;w<=capacity;w++) {
                int notTake=prev[w];
                int take=Integer.MIN_VALUE;
                if(wt[i]<=w) take=val[i]+prev[w-wt[i]];
                prev[w]=Math.max(notTake, take);
            }
        }
        return prev[capacity];
    }
    public static void main(String[] args) {
        int[] val={6,1,7,7};
        int[] wt={1,3,4,5};
        int capacity=8;
        System.out.println(knapsack(wt,val,capacity,wt.length));
    }    
}

```

### Python
```python
def knapsack(wt, val, capacity, n):
    prev = [0] * (capacity + 1)

    for w in range(capacity + 1):
        prev[w] = (w // wt[0]) * val[0]

    for i in range(1, n):
        for w in range(capacity + 1):
            not_take = prev[w]
            take = float('-inf')
            if wt[i] <= w:
                take = val[i] + prev[w - wt[i]]
            prev[w] = max(not_take, take)

    return prev[capacity]

if __name__ == "__main__":
    val = [6, 1, 7, 7]
    wt = [1, 3, 4, 5]
    capacity = 8
    print(knapsack(wt, val, capacity, len(wt)))

```

### C++
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int knapsack(vector<int>& wt, vector<int>& val, int capacity, int n) {
    vector<int> prev(capacity + 1, 0);

    for (int w = 0; w <= capacity; w++) {
        prev[w] = (w / wt[0]) * val[0];
    }

    for (int i = 1; i < n; i++) {
        for (int w = 0; w <= capacity; w++) {
            int notTake = prev[w];
            int take = INT_MIN;
            if (wt[i] <= w)
                take = val[i] + prev[w - wt[i]];
            prev[w] = max(notTake, take);
        }
    }

    return prev[capacity];
}

int main() {
    vector<int> val = {6, 1, 7, 7};
    vector<int> wt = {1, 3, 4, 5};
    int capacity = 8;
    cout << knapsack(wt, val, capacity, wt.size()) << endl;
    return 0;
}

```
