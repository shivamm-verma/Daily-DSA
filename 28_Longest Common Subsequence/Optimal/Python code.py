def longestCommonSubsequence(text1, text2):
    n = len(text1)
    m = len(text2)
    dp = [[0] * (m + 1) for _ in range(n + 1)]

    for i in range(1, n + 1):
        for j in range(1, m + 1):
            if text1[i - 1] == text2[j - 1]:
                dp[i][j] = 1 + dp[i - 1][j - 1]
            else:
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
    
    return dp[n][m]

# Test case
text1 = "abcde"
text2 = "ace"
print(longestCommonSubsequence(text1, text2))
