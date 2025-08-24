#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool solveRec(string& s, string& p, int i, int j) {
        if (i == s.length() && j == p.length()) {
            return true;
        }
        if (j == p.length()) {
            return false;
        }

        bool currMatch = (i < s.length()) && (p[j] == '.' || s[i] == p[j]);

        if (j + 1 < p.length() && p[j + 1] == '*') {
            bool emptyCase = solveRec(s, p, i, j + 2);
            bool precElementCase = currMatch && solveRec(s, p, i + 1, j);
            return emptyCase || precElementCase;
        } 
        else if (currMatch) {
            return solveRec(s, p, i + 1, j + 1);
        } 
        else {
            return false;
        }
    }

    bool isMatch(string s, string p) {
        return solveRec(s, p, 0, 0);
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