## Problem Burst Balloon
Given `n` balloons, indexed `0..n-1`, each with a positive integer `nums[i]`. If you burst balloon `i`, you earn nums `[left] * nums[i] * nums[right]` coins, where left and right are the adjacent indices of `i` at the time of bursting (they may change after bursting). You're to find the maximum coins that can be obtained by bursting all balloons optimally.

Hint: Add virtual balloons 1 at both ends to simplify.

```
Example

Input: [3,1,5,8]
Output: 167
Explanation: One optimal order yields 167.
```

## Approach (Divide & Conquer + Memo)

Consider `dp[l][r] = max` coins obtainable from bursting all balloons strictly between indices `l` and `r` (exclusive). Choose last balloon `i` between `l` and `r` to burst; then `coins = nums[l]*nums[i]*nums[r] + dp[l][i] + dp[i][r]`. Use memoization/DP.

## Code

### Python
```python
class Solution:
    def maxCoins(self, nums: list[int]) -> int:
        n = len(nums)
        arr = [1] + nums + [1]
        m = n + 2
        dp = [[0]*m for _ in range(m)]
        for length in range(2, m):
            for left in range(0, m - length):
                right = left + length
                for i in range(left+1, right):
                    dp[left][right] = max(dp[left][right], arr[left]*arr[i]*arr[right] + dp[left][i] + dp[i][right])
        return dp[0][m-1]

# quick test
if __name__ == '__main__':
    sol = Solution()
    print(sol.maxCoins([3,1,5,8]))  # 167
```


### Java
```java
package Recursion and Backtracking.BurstBalloon;

public class java_code {
    public int maxCoins(int[] nums) {
        int n = nums.length;
        int[] arr = new int[n + 2];
        arr[0] = 1; arr[n + 1] = 1;
        for (int i = 1; i <= n; i++) arr[i] = nums[i - 1];
        int m = n + 2;
        int[][] dp = new int[m][m];

        for (int length = 2; length < m; length++) {
            for (int l = 0; l + length < m; l++) {
                int r = l + length;
                for (int i = l + 1; i < r; i++) {
                    int val = arr[l] * arr[i] * arr[r] + dp[l][i] + dp[i][r];
                    if (val > dp[l][r]) dp[l][r] = val;
                }
            }
        }
        return dp[0][m - 1];
    }

    public static void main(String[] args) {
        java_code s = new java_code();
        System.out.println(s.maxCoins(new int[]{3,1,5,8})); // 167
    }
}

```

### C++
```cpp
#include <bits/stdc++.h>
using namespace std;

int maxCoins(vector<int>& nums) {
    int n = nums.size();
    vector<int> arr(n + 2, 1);
    for (int i = 0; i < n; ++i) arr[i+1] = nums[i];
    int m = n + 2;
    vector<vector<int>> dp(m, vector<int>(m, 0));
    for (int len = 2; len < m; ++len) {
        for (int l = 0; l + len < m; ++l) {
            int r = l + len;
            for (int i = l + 1; i < r; ++i) {
                int val = arr[l] * arr[i] * arr[r] + dp[l][i] + dp[i][r];
                dp[l][r] = max(dp[l][r], val);
            }
        }
    }
    return dp[0][m-1];
}

int main(){
    vector<int> nums = {3,1,5,8};
    cout << maxCoins(nums) << "\n"; // 167
}
```
## Complexity

- Time: O(n^3) naive (n^2 states, O(n) per state)

- Space: O(n^2)