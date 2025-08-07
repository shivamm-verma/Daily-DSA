#include <iostream>
#include <vector>
using namespace std;

int uniquePaths(int i, int j, vector<vector<int>>& dp) {
    if (i == 0 && j == 0)
        return 1;
    if (i < 0 || j < 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];

    int up = uniquePaths(i - 1, j, dp);
    int left = uniquePaths(i, j - 1, dp);
    return dp[i][j] = up + left;
}

int main() {
    int m = 3, n = 7;
    vector<vector<int>> dp(m, vector<int>(n, -1));
    cout << uniquePaths(m - 1, n - 1, dp) << endl;
    return 0;
}
