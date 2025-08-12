#include <iostream>
#include <vector>
#include <string>
using namespace std;

int longestCommonSubsequence(string text1, string text2, int ind1, int ind2, vector<vector<int>>& dp) {
    if (ind1 < 0 || ind2 < 0)
        return 0;
    if (dp[ind1][ind2] != -1)
        return dp[ind1][ind2];
    if (text1[ind1] == text2[ind2])
        return dp[ind1][ind2] = 1 + longestCommonSubsequence(text1, text2, ind1 - 1, ind2 - 1, dp);
    else
        return dp[ind1][ind2] = max(longestCommonSubsequence(text1, text2, ind1 - 1, ind2, dp),
                                    longestCommonSubsequence(text1, text2, ind1, ind2 - 1, dp));
}

int main() {
    string text1 = "abcde";
    string text2 = "ace";
    int n = text1.length(), m = text2.length();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    cout << longestCommonSubsequence(text1, text2, n - 1, m - 1, dp) << endl;
    return 0;
}
