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
