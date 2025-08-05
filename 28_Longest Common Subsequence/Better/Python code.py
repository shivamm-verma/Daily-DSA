def longestCommonSubsequence(text1, text2, ind1, ind2, dp):
    if ind1 < 0 or ind2 < 0:
        return 0
    if dp[ind1][ind2] != -1:
        return dp[ind1][ind2]
    if text1[ind1] == text2[ind2]:
        dp[ind1][ind2] = 1 + longestCommonSubsequence(text1, text2, ind1 - 1, ind2 - 1, dp)
    else:
        dp[ind1][ind2] = max(longestCommonSubsequence(text1, text2, ind1 - 1, ind2, dp),
                             longestCommonSubsequence(text1, text2, ind1, ind2 - 1, dp))
    return dp[ind1][ind2]

# Test case
text1 = "abcde"
text2 = "ace"
n, m = len(text1), len(text2)
dp = [[-1 for _ in range(m)] for _ in range(n)]
print(longestCommonSubsequence(text1, text2, n - 1, m - 1, dp))
