#include <bits/stdc++.h>
using namespace std;

string minWindowOptimal(string s, string t) {
    if (s.size() < t.size()) return "";

    vector<int> need(128, 0), window(128, 0);
    int required = 0, formed = 0;
    for (char c : t) {
        if (need[c] == 0) required++;
        need[c]++;
    }

    int l = 0, r = 0, minLen = INT_MAX, start = 0;
    while (r < s.size()) {
        char c = s[r];
        window[c]++;
        if (window[c] == need[c]) formed++;

        while (l <= r && formed == required) {
            if (r - l + 1 < minLen) {
                minLen = r - l + 1;
                start = l;
            }
            char lc = s[l];
            window[lc]--;
            if (window[lc] < need[lc]) formed--;
            l++;
        }
        r++;
    }
    return minLen == INT_MAX ? "" : s.substr(start, minLen);
}

int main() {
    string s = "ADOBECODEBANC", t = "ABC";
    cout << minWindowOptimal(s, t) << endl; // Expected: BANC
}
