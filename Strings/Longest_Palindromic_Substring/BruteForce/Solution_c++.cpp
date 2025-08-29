#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindromeBrute(string s) {
        int n = s.size();
        string longest = "";
        
        auto isPalindrome = [&](int l, int r) {
            while(l < r) {
                if(s[l] != s[r]) return false;
                l++; r--;
            }
            return true;
        };
        
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                if(isPalindrome(i, j)) {
                    if(j - i + 1 > (int)longest.size()) {
                        longest = s.substr(i, j - i + 1);
                    }
                }
            }
        }
        return longest;
    }
};

int main() {
    Solution sol;
    cout << sol.longestPalindromeBrute("babad") << endl; // "bab" or "aba"
    cout << sol.longestPalindromeBrute("cbbd") << endl;  // "bb"
}
