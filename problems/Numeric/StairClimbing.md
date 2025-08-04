# 🧗‍♂️ Problem: Climbing Stairs

Given `n` steps, you can climb either `1` or `2` steps at a time. Your task is to find how many distinct ways you can climb to the top.

---

### 📌 Example

**Input:** `n = 5`  
**Output:** `8`  
**Explanation:** There are 8 ways to climb 5 steps are:
- 1+1+1+1+1
- 1+1+1+2
- 1+1+2+1
- 1+2+1+1
- 2+1+1+1
- 2+2+1
- 2+1+2
- 1+2+2


**Input:** `n = 2`
**Output:** `2`
**Explanation:** There are 2 ways to climb 2 steps are:
- 1+1
- 2 

---

## ✅ Brute Force (Recursive)

### 🔍 Intuition
Try all combinations of taking 1 or 2 steps recursively.

### ⏱ Time Complexity:
`O(2^n)` — exponential due to overlapping subproblems.

### 📦 Space Complexity:
`O(n)` — recursion stack.


---

## ✅ Better Approach (Top-Down with Memoization)

### 🔍 Intuition
Use a DP array to store intermediate results (memoization).Instead of calling multiple same sub problems store the results and use them.

### ⏱ Time Complexity:
`O(n)`

### 📦 Space Complexity:
`O(n)`

---


## ✅ Most Optimal (Space-Optimized)

### 🔍 Intuition
Just track the last two results instead of the full DP array.

### ⏱ Time Complexity:
`O(n)`

### 📦 Space Complexity:
`O(1)`


---

## 📌 Summary
```text
+------------------+------------------+------------------+
| Approach         | Time Complexity  | Space Complexity |
+------------------+------------------+------------------+
| Brute Force      | O(2^n)           | O(n)             |
| Memoization      | O(n)             | O(n)             |
| Space-Optimized  | O(n)             | O(1)             |
+------------------+------------------+------------------+

```
---

## Code
### Java
```java
import java.util.Scanner;

public class ClimbingStairsOptimized {
    public static int climbStairs(int n) {
        if (n == 0 || n == 1) return 1;

        int prev = 1, curr = 1;
        for (int i = 2; i <= n; i++) {
            int temp = curr;
            curr = prev + curr;
            prev = temp;
        }
        return curr;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of steps: ");
        int n = sc.nextInt();
        System.out.println("The total number of ways are: " + climbStairs(n));
    }
}
// This code implements an optimized solution for the Climbing Stairs problem using constant space.
```

### Python 
```python
def climb_stairs(n):
    if n == 0 or n == 1:
        return 1

    prev, curr = 1, 1
    for i in range(2, n + 1):
        curr, prev = prev + curr, curr
    return curr

if __name__ == "__main__":
    n = int(input("Enter the number of steps: "))
    print("The total number of ways are:", climb_stairs(n))

```

### C++
```cpp
#include <bits/stdc++.h>
using namespace std;
 int climbStairs(int n) {
        if (n == 0 || n == 1) {
            return 1;
        }
        int prev = 1, curr = 1;
        for (int i = 2; i <= n; i++) {
            int temp = curr;
            curr = prev + curr;
            prev = temp;
        }
        return curr;
    }
int main()
{
    int n;
    cout << "Enter the number of steps: ";
    cin >> n;
    cout << "The total number of ways are:" << climbStairs(n) << endl;
    return 0;
}
```
---