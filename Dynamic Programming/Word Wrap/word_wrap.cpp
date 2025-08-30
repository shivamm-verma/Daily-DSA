#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solveWordWrap(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, 0);
        vector<int> ans(n, 0);
        dp[n - 1] = 0;
        ans[n - 1] = n - 1;

        
        for (int i = n - 2; i >= 0; i--) {
            int currlen = -1;
            dp[i] = INT_MAX;
            for (int j = i; j < n; j++) {
                currlen += arr[j] + 1;
                if (currlen > k) break;

                int cost;
                if (j == n - 1) {
                    cost = 0;
                } else {
                    cost = (k - currlen) * (k - currlen) + dp[j + 1];
                }

                if (cost < dp[i]) {
                    dp[i] = cost;
                    ans[i] = j;
                }
            }
        }

        
        int res = 0;
        int i = 0;
        while (i < n) {
            int pos = 0;
            for (int j = i; j <= ans[i]; j++) {
                pos += arr[j];
            }
            int x = ans[i] - i;
            if (ans[i] + 1 != n) {
                res += (k - x - pos) * (k - x - pos);
            }
            i = ans[i] + 1;
        }
        return res;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    int k;
    cin >> k;

    Solution sol;
    cout << sol.solveWordWrap(arr, k) << endl;
    return 0;
}
