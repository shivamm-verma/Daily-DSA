#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string expandAroundCenter(string s, int left, int right) {
        while(left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        return s.substr(left + 1, right - left - 1);
    }
    
    string longestPalindrome(string s) {
        string longest = "";
        for(int i = 0; i < s.size(); i++) {
            string odd = expandAroundCenter(s, i, i);
            string even = expandAroundCenter(s, i, i+1);
            
            string candidate = (odd.size() > even.size()) ? odd : even;
            if(candidate.size() > longest.size()) {
                longest = candidate;
            }
        }
        return longest;
    }
};

int main() {
    Solution sol;
    cout << sol.longestPalindrome("babad") << endl; // "bab" or "aba"
    cout << sol.longestPalindrome("cbbd") << endl;  // "bb"
}
