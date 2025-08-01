#include <bits/stdc++.h>
using namespace std;

int climbStairs(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    vector<int> dp(n + 1);
    dp[0] = dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int main() {
    int n;
    cout << "Enter the number of steps: ";
    cin >> n;
    cout << "The total number of ways are: " << climbStairs(n) << endl;
    return 0;
}
