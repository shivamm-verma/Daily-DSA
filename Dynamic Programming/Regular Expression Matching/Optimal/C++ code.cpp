#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool solveTab(string& s, string& p, int m, int n) {
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[m][n] = true;
        for (int i = m; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                bool currMatch = (i < m) && (p[j] == '.' || s[i] == p[j]);
                if (j + 1 < n && p[j + 1] == '*') {
                    dp[i][j] = dp[i][j + 2] || (currMatch && dp[i + 1][j]);
                } else if (currMatch) {
                    dp[i][j] = dp[i + 1][j + 1];
                } else {
                    dp[i][j] = false;
                }
            }
        }
        return dp[0][0];
    }

    bool isMatch(string s, string p) {
        return solveTab(s, p, s.length(), p.length());
    }
};

int main() {
    Solution sol;
    string s = "mississippi";
    string p = "mis*is*p*.";
    cout << "Input String: \"" << s << "\", Pattern: \"" << p << "\"" << endl;
    cout << "Output: " << (sol.isMatch(s, p) ? "true" : "false") << endl;
    return 0;
}
