#include <bits/stdc++.h>
using namespace std;

bool containsAll(string sub, string t) {
    vector<int> count(128, 0);
    for (char c : sub) count[c]++;
    for (char c : t) if (--count[c] < 0) return false;
    return true;
}

string minWindowBrute(string s, string t) {
    int n = s.size(), minLen = INT_MAX;
    string ans = "";
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            string sub = s.substr(i, j - i + 1);
            if (containsAll(sub, t) && sub.size() < minLen) {
                ans = sub;
                minLen = sub.size();
            }
        }
    }
    return ans;
}

int main() {
    string s = "ADOBECODEBANC", t = "ABC";
    cout << minWindowBrute(s, t) << endl; // Expected: BANC
}
