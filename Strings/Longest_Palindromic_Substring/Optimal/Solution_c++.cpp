#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if(s.empty()) return "";
        
        // Transform string: add separators
        string T = "^";
        for(char c : s) {
            T += "#" + string(1, c);
        }
        T += "#$";
        
        int n = T.size();
        vector<int> P(n, 0);
        int center = 0, right = 0;
        
        for(int i = 1; i < n-1; i++) {
            int mirror = 2*center - i;
            
            if(i < right) {
                P[i] = min(right - i, P[mirror]);
            }
            
            // Expand around center
            while(T[i + (1 + P[i])] == T[i - (1 + P[i])]) {
                P[i]++;
            }
            
            // Update center & right
            if(i + P[i] > right) {
                center = i;
                right = i + P[i];
            }
        }
        
        // Find max length palindrome
        int maxLen = 0, centerIndex = 0;
        for(int i = 1; i < n-1; i++) {
            if(P[i] > maxLen) {
                maxLen = P[i];
                centerIndex = i;
            }
        }
        
        int start = (centerIndex - maxLen) / 2;
        return s.substr(start, maxLen);
    }
};

int main() {
    Solution sol;
    cout << sol.longestPalindrome("babad") << endl; // "bab" or "aba"
    cout << sol.longestPalindrome("cbbd") << endl;  // "bb"
}
