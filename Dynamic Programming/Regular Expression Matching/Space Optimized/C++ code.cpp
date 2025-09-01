#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool solveTabSO(string& s, string& p, int m, int n) {
        vector<bool> prev(n + 1, false);
        vector<bool> curr(n + 1, false);
        prev[n] = true;

        for (int i = m; i >= 0; --i) {
            curr[n] = (i == m);
            for (int j = n - 1; j >= 0; --j) {
                bool first_match = (i < m && (p[j] == s[i] || p[j] == '.'));
                if (j + 1 < n && p[j + 1] == '*') {
                    curr[j] = curr[j + 2] || (first_match && prev[j]);
                } else {
                    curr[j] = first_match && prev[j + 1];
                }
            }
            prev = curr;
        }
        return prev[0];
    }

    bool isMatch(string s, string p) {
        return solveTabSO(s, p, s.length(), p.length());
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