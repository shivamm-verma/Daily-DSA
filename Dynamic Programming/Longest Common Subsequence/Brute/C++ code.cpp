#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int longestCommonSubsequence(string text1, string text2, int ind1, int ind2) {
    if (ind1 < 0 || ind2 < 0)
        return 0;
    if (text1[ind1] == text2[ind2])
        return 1 + longestCommonSubsequence(text1, text2, ind1 - 1, ind2 - 1);
    else
        return max(longestCommonSubsequence(text1, text2, ind1 - 1, ind2),
                   longestCommonSubsequence(text1, text2, ind1, ind2 - 1));
}

int main() {
    string text1 = "abcde";
    string text2 = "ace";
    cout << longestCommonSubsequence(text1, text2, text1.length() - 1, text2.length() - 1) << endl;
    return 0;
}
