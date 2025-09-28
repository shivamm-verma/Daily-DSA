#include <bits/stdc++.h>
using namespace std;

bool allCovered(vector<int>& need, const vector<char>& required) {
    for (char c : required) if (need[c] > 0) return false;
    return true;
}

string minWindowBetter(string s, string t) {
    int n = s.size(), minLen = INT_MAX;
    string ans = "";
    vector<char> required;
    vector<int> requiredFlag(128, 0);
    for (char c : t) {
        if (!requiredFlag[c]) {
            required.push_back(c);
            requiredFlag[c] = 1;
        }
    }
    for (int i = 0; i < n; i++) {
        vector<int> need(128, 0);
        for (char c : t) need[c]++;
        for (int j = i; j < n; j++) {
            need[s[j]]--;
            if (allCovered(need, required)) {
                if (j - i + 1 < minLen) {
                    ans = s.substr(i, j - i + 1);
                    minLen = j - i + 1;
                }
                break;
            }
        }
    }
    return ans;
}

int main() {
    string s = "ADOBECODEBANC", t = "ABC";
    cout << minWindowBetter(s, t) << endl; // Expected: BANC
}
