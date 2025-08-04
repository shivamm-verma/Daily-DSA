## 🧠 Problem
Given an integer array ```nums```, rotate the array to the right by `k` steps, where k is non-negative.

```
Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
---------------------------------------------------

Example 2:

Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
```
---
## Constraints:
```
1 <= nums.length <= 105
-231 <= nums[i] <= 231 - 1
0 <= k <= 105
```

---

## Approach

Key Observations:  
Rotating an array by k = n (where n is array length) results in the original array.
Therefore, we compute k = k % n to handle cases when k > n.
 
Steps:  
- Reverse the first part of the array (from index 0 to n - k - 1).
- Reverse the second part (from index n - k to n - 1).
- Reverse the entire array.  
These three reversals together achieve the desired rotation.

A helper function is used to reverse any portion of the array in-place using two pointers (st and end).

---
## Code

### Java
```java
public class java_code {
    public void rotate(int[] nums, int k) {
        // after n rotations original arrat wil be restored
        int n = nums.length;
        k = k%n;
        reverse(nums,0,n-k-1);
        reverse(nums,n-k,n-1);
        reverse(nums,0,n-1);

    }

    void reverse(int[] nums,int st,int end){
        while(st<=end){
            int temp = nums[st];
            nums[st] = nums[end];
            nums[end] = temp;
            st++;
            end--;
        }
    }
}
```

### Python
```python
class Solution:
    def rotate(self, nums: list[int], k: int) -> None:
        n = len(nums)
        k = k % n

        self.reverse(nums, 0, n - k - 1)
        self.reverse(nums, n - k, n - 1)
        self.reverse(nums, 0, n - 1)

    def reverse(self, nums: list[int], start: int, end: int) -> None:
        while start <= end:
            nums[start], nums[end] = nums[end], nums[start]
            start += 1
            end -= 1
```

### C++
```cpp
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;

        reverse(nums, 0, n - k - 1);
        reverse(nums, n - k, n - 1);
        reverse(nums, 0, n - 1);
    }

    void reverse(vector<int>& nums, int start, int end) {
        while (start <= end) {
            swap(nums[start], nums[end]);
            start++;
            end--;
        }
    }
};
```
---
## Complexities
- Time: O(n) — Each element is reversed at most twice.
- Extra Space: O(1) — In-place algorithm.