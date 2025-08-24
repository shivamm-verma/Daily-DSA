#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool solveMem(string& s, string& p, int i, int j, vector<vector<int>>& dp) {
        if (i == s.length() && j == p.length()) return true;
        if (j == p.length()) return false;
        
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        bool currMatch = (i < s.length()) && (p[j] == '.' || s[i] == p[j]);
        bool ans;

        if (j + 1 < p.length() && p[j + 1] == '*') {
            bool emptyCase = solveMem(s, p, i, j + 2, dp);
            bool precElementCase = currMatch && solveMem(s, p, i + 1, j, dp);
            ans = emptyCase || precElementCase;
        } 
        else if (currMatch) {
            ans = solveMem(s, p, i + 1, j + 1, dp);
        } 
        else {
            ans = false;
        }
        
        dp[i][j] = ans;
        return dp[i][j];
    }

    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return solveMem(s, p, 0, 0, dp);
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