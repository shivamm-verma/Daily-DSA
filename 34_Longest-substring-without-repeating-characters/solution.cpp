#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> lastSeen;
    int left = 0, maxLen = 0;

    for (int right = 0; right < s.length(); ++right) {
        char currentChar = s[right];

        // If character is in map and its index is in current window
        if (lastSeen.count(currentChar) && lastSeen[currentChar] >= left) {
            left = lastSeen[currentChar] + 1;
        }

        lastSeen[currentChar] = right;
        maxLen = max(maxLen, right - left + 1);
    }

    return maxLen;
}

int main() {
    string s = "abcabcbb";
    cout << "Length of longest substring without repeating characters: " << lengthOfLongestSubstring(s) << endl;
    return 0;
}
