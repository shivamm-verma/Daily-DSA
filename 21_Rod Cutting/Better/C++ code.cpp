#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int cutRod(vector<int>& price, int ind, int n, vector<vector<int>>& dp) {
    if (ind == 0)
        return n * price[0];
    if (dp[ind][n] != -1)
        return dp[ind][n];
    
    int notTake = cutRod(price, ind - 1, n, dp);
    int take = INT_MIN;
    int rodLen = ind + 1;
    if (rodLen <= n)
        take = price[ind] + cutRod(price, ind, n - rodLen, dp);
    
    return dp[ind][n] = max(take, notTake);
}

int main() {
    vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};
    int n = price.size();
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    cout << cutRod(price, n - 1, n, dp) << endl;
    return 0;
}
