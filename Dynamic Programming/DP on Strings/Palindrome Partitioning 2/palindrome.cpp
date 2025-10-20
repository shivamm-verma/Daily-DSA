#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCut(string s) {
        // If the string is empty, return 0 cuts.
        if (s.empty()) return 0;
        
        int n = s.size();
      
        // isPalindrome[i][j] indicates whether substring s[i...j] is a palindrome
        vector<vector<bool>> isPalindrome(n, vector<bool>(n, true));
      
        // Build the palindrome lookup table using dynamic programming
        // Start from the end of string and work backwards
        for (int start = n - 1; start >= 0; --start) {
            for (int end = start + 1; end < n; ++end) {
                // A substring is palindrome if:
                // 1. First and last characters match
                // 2. Inner substring is also a palindrome (or length <= 2)
                isPalindrome[start][end] = (s[start] == s[end]) && isPalindrome[start + 1][end - 1];
            }
        }
      
        // minCuts[i] represents minimum cuts needed for substring s[0...i]
        vector<int> minCuts(n);
      
        // Initialize: worst case is to cut between every character
        for (int i = 0; i < n; ++i) {
            minCuts[i] = i;  // Maximum i cuts needed for string of length i+1
        }
      
        // Calculate minimum cuts for each position
        for (int end = 1; end < n; ++end) {
            for (int start = 0; start <= end; ++start) {
                // If s[start...end] is a palindrome
                if (isPalindrome[start][end]) {
                    if (start == 0) {
                        // Entire substring from beginning is palindrome, no cuts needed
                        minCuts[end] = 0;
                    } else {
                        // Add one cut after position (start-1)
                        minCuts[end] = min(minCuts[end], minCuts[start - 1] + 1);
                    }
                }
            }
        }
      
        // Return minimum cuts for entire string
        return minCuts[n - 1];
    }
};
