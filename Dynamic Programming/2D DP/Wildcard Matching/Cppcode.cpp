#include <bits/stdc++.h>
using namespace std;
bool isMatch(string s, string p) {
    int n = s.size(), m = p.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
    dp[0][0] = true;
    for (int j = 1; j <= m; j++) {
        if (p[j - 1] == '*')
            dp[0][j] = dp[0][j - 1];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char pc = p[j - 1];
            if (pc == s[i - 1] || pc == '?') {
                dp[i][j] = dp[i - 1][j - 1];
            } else if (pc == '*') {
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
            }
        }
    }
    return dp[n][m];
}
int main() {
    string s, p;
    cout << "Enter string s: ";
    getline(cin, s);
    cout << "Enter pattern p: ";
    getline(cin, p);
    if (isMatch(s, p))
        cout << "Match: YES\n";
    else
        cout << "Match: NO\n";
}
