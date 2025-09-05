#include <bits/stdc++.h>
using namespace std;
int minCoins(vector<int>& coins, int X) {
    vector<int> dp(X + 1, X + 1);
    dp[0] = 0;
    for (int i = 1; i <= X; i++) {
        for (int coin : coins) {
            if (coin <= i) {
                dp[i] = min(dp[i], 1 + dp[i - coin]);
            }
        }
    }
    return (dp[X] > X) ? -1 : dp[X];
}
int main() {
    int n, X;
    cout << "Enter number of coin types: ";
    cin >> n;
    vector<int> coins(n);
    cout << "Enter coin denominations: ";
    for (int i = 0; i < n; i++) cin >> coins[i];
    cout << "Enter the amount X: ";
    cin >> X;
    int result = minCoins(coins, X);
    cout << "Minimum coins required: " << result << endl;
}
