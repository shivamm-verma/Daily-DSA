## ✅ DSA Question: Maximum Product Subarray

---

### 🧠 Problem  
Given an array `arr` of size `n` containing positive and negative numbers, find the maximum product obtained by a subarray. 

A subarry is a contiguous part of an array.

**Examples:**  
- Input: 
  `n = 4`
  `arr = [2, 3, -2, 4]` 
  Output: `6`  
- Input: 
  `n = 6`
  `arr = [-2, 6, -3, -10, 0, 2]` 
  Output: `180`

---

## 🧭 Approach

1. Initialize three variables: 
   – `curr_max` to track max product ending at current index – `curr_min` to track min product (in case a negative flips it) 
   – `max_product` to hold the overall max seen so far

2. Iterate through the array: 
   – Update `curr_max` and `curr_min` using current value and previous results 
   – Choose maximum/minimum among: current element, product with `curr_max`, product with `curr_min` 
   – Update `max_product` if `curr_max` is larger

3. Return the `max_product` found at the end.

---

## 🔁 Generic Logic (Pseudocode)
```plaintext
function maxProduct(arr):
    curr_max = arr[0]
    curr_min = arr[0]
    max_product = arr[0]
    for i from 1 to length of arr - 1:
        temp = max(arr[i], arr[i] * curr_max, arr[i] * curr_min)
        curr_min = min(arr[i], arr[i] * curr_max, arr[i] * curr_min)
        curr_max = temp
        max_product = max(max_product, curr_max)
    return max_product
```

## Code

### Java
```java
import java.util.*;
public class Main{
    // optimized code in java
    static int maxProduct(int[] arr, int n) {
        int currmax = arr[0];
        int currmin = arr[0];
        int maxp = arr[0];
        
        for(int i=1; i<n; i++){
            int temp = Math.max(arr[i], Math.max(arr[i]*currmax, arr[i]*currmin));
            currmin = Math.min(arr[i], Math.min(arr[i]*currmax, arr[i]*currmin));
            currmax = temp;
            maxp = Math.max(maxp, currmax);
        }
        return maxp;
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for(int i=0; i<n; i++){
            arr[i] = sc.nextInt();
        }
        int res = maxProduct(arr, n);
        System.out.println(res);
        sc.close();
    }
}
```

### Python 
```python
def max_product(arr):
    curr_max = arr[0]
    curr_min = arr[0]
    maxp = arr[0]

    for i in range(1, len(arr)):
        temp = max(arr[i], arr[i] * curr_max, arr[i] * curr_min)
        curr_min = min(arr[i], arr[i] * curr_max, arr[i] * curr_min)
        curr_max = temp
        maxp = max(maxp, curr_max)
    return maxp

if __name__ == "__main__":
    n = int(input())
    arr = list(map(int, input().split()))
    result = max_product(arr)
    print(result)

```

### C++
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxProduct(vector<int>& arr, int n) {
    int currmax = arr[0], currmin = arr[0], maxp = arr[0];

    for(int i = 1; i < n; ++i) {
        int temp = max({arr[i], arr[i]*currmax, arr[i]*currmin});
        currmin = min({arr[i], arr[i]*currmax, arr[i]*currmin});
        currmax = temp;
        maxp = max(maxp, currmax);
    }
    return maxp;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int res = maxProduct(arr, n);
    cout << res << endl;

    return 0;
}

```
---
## ⏱️ Complexities
 >Time Complexity
**O(n)** — single-pass through the array, where n = number of elements in array.
 >Space Complexity
**O(1)** — only constant space used for tracking variables.