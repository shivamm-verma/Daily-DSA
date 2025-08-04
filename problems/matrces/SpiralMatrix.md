## ✅ DSA Question: Spiral Matrix

## 🧠 Problem
Given an m x n matrix, return all elements of the matrix in spiral order.

## Examples:

Input:[[1,2,3], -> Output: [1,2,3,6,9,8,7,4,5]
      [4,5,6],
      [7,8,9]]


Input:[[1,2,3,4], -> Output: [1,2,3,4,8,12,11,10,9,5,6,7]
      [5,6,7,8],
      [9,10,11,12]]


## 🧭 Approach
1. Define four boundaries:
    – top = 0
    – bottom = number of rows - 1
    – left = 0
    – right = number of columns - 1

2. Traverse the matrix in spiral order while top <= bottom and left <= right:

    * Traverse left to right across the top row

    * Traverse top to bottom down the rightmost column

    * Traverse right to left across the bottom row (if still valid)

    * Traverse bottom to top up the leftmost column (if still valid)

    * Update the boundaries after each pass

3. Continue until all elements are added to the result.

## 🔁 Generic Logic (Pseudocode)
```
function spiralOrder(matrix):
    top = 0
    bottom = rows - 1
    left = 0
    right = cols - 1
    result = []

    while top <= bottom and left <= right:
        for i from left to right:
            result.append(matrix[top][i])
        top += 1

        for i from top to bottom:
            result.append(matrix[i][right])
        right -= 1

        if top <= bottom:
            for i from right to left:
                result.append(matrix[bottom][i])
            bottom -= 1

        if left <= right:
            for i from bottom to top:
                result.append(matrix[i][left])
            left += 1

    return result
```

---
## Code

### Java
```java
import java.util.*;

class java code {
    public static List<Integer> spiralOrder(int[][] matrix) {
        int n=matrix.length;
        int m=matrix[0].length;
        int top=0,left=0;
        int bottom=n-1,right=m-1;
        List<Integer> ans=new ArrayList<>();
        while(top<=bottom && left<=right) {
            for(int i=left;i<=right;i++) {
                ans.add(matrix[top][i]);
            }
            top++;
            for(int i=top;i<=bottom;i++) {
                ans.add(matrix[i][right]);
            }
            right--;
            if(top<=bottom) {
                for(int i=right;i>=left;i--) {
                    ans.add(matrix[bottom][i]);
                }
                bottom--;
            }
            if(left<=right) {
                for(int i=bottom;i>=top;i--) {
                    ans.add(matrix[i][left]);
                }
                left++;
            }
        }
        return ans;
    }
    public static void main(String[] args) {
        int[][] matrix={{1,2,3},{4,5,6},{7,8,9}};
        List<Integer> res=new ArrayList<>();
        res=spiralOrder(matrix);
        for(int it:res) System.out.print(it);
    }    
}
```

### Python
```python
from typing import List

def spiralOrder(matrix: List[List[int]]) -> List[int]:
    n = len(matrix)
    m = len(matrix[0])
    top, left = 0, 0
    bottom, right = n - 1, m - 1
    ans = []

    while top <= bottom and left <= right:
        for i in range(left, right + 1):
            ans.append(matrix[top][i])
        top += 1

        for i in range(top, bottom + 1):
            ans.append(matrix[i][right])
        right -= 1

        if top <= bottom:
            for i in range(right, left - 1, -1):
                ans.append(matrix[bottom][i])
            bottom -= 1

        if left <= right:
            for i in range(bottom, top - 1, -1):
                ans.append(matrix[i][left])
            left += 1

    return ans

# Example usage
matrix = [[1,2,3],[4,5,6],[7,8,9]]
result = spiralOrder(matrix)
print(result)
```

### C++ 
```cpp
#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    int top = 0, left = 0;
    int bottom = n - 1, right = m - 1;
    vector<int> ans;

    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; i++) {
            ans.push_back(matrix[top][i]);
        }
        top++;

        for (int i = top; i <= bottom; i++) {
            ans.push_back(matrix[i][right]);
        }
        right--;

        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
        }

        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
    }
    return ans;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    vector<int> result = spiralOrder(matrix);
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}
```
---

## ⏱️ Complexities
 >Time Complexity
**O(m × n)** — Every element is visited once.

 >Space Complexity
**O(m × n)** — For storing the result (if returned as a new list).