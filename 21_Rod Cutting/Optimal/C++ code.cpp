#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int cutRod(vector<int>& price) {
    int n = price.size();
    vector<vector<int>> dp(n, vector<int>(n + 1, 0));

    // Base case: only using rod of length 1
    for (int p = 0; p <= n; p++) {
        dp[0][p] = p * price[0];
    }

    for (int i = 1; i < n; i++) {
        for (int p = 0; p <= n; p++) {
            int notTake = dp[i - 1][p];
            int take = INT_MIN;
            int rodLen = i + 1;
            if (rodLen <= p)
                take = price[i] + dp[i][p - rodLen];
            dp[i][p] = max(notTake, take);
        }
    }

    return dp[n - 1][n];
}

int main() {
    vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};
    cout << cutRod(price) << endl;
    return 0;
}
