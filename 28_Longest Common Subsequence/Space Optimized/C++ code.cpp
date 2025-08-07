#include <iostream>
#include <vector>
#include <string>
using namespace std;

int longestCommonSubsequence(string text1, string text2) {
    int n = text1.length();
    int m = text2.length();
    vector<int> prev(m + 1, 0);

    for (int i = 1; i <= n; ++i) {
        vector<int> cur(m + 1, 0);
        for (int j = 1; j <= m; ++j) {
            if (text1[i - 1] == text2[j - 1])
                cur[j] = 1 + prev[j - 1];
            else
                cur[j] = max(prev[j], cur[j - 1]);
        }
        prev = cur;
    }
    return prev[m];
}

int main() {
    string text1 = "abcde";
    string text2 = "ace";
    cout << longestCommonSubsequence(text1, text2) << endl;
    return 0;
}
