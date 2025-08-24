#include <iostream>
#include <vector>
using namespace std;
int climbStairs(int n) {
    if (n <= 2) return n;
    vector<int> dp(n + 1);
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}
int climbStairsOptimized(int n) {
    if (n <= 2) return n;
    int prev2 = 1;
    int prev1 = 2;
    int current;
    for (int i = 3; i <= n; i++) {
        current = prev1 + prev2;
        prev2 = prev1;
        prev1 = current;
    }
    return prev1;
}
int main() {
    int n;
    cout << "Enter number of stairs: ";
    cin >> n;
    int result1 = climbStairs(n);
    int result2 = climbStairsOptimized(n);
    cout << "Number of ways to climb " << n << " stairs (DP): " << result1 << endl;
    cout << "Number of ways to climb " << n << " stairs (Optimized): " << result2 << endl;
}
