def longestCommonSubsequence(text1, text2, ind1, ind2):
    if ind1 < 0 or ind2 < 0:
        return 0
    if text1[ind1] == text2[ind2]:
        return 1 + longestCommonSubsequence(text1, text2, ind1 - 1, ind2 - 1)
    else:
        return max(longestCommonSubsequence(text1, text2, ind1 - 1, ind2),
                   longestCommonSubsequence(text1, text2, ind1, ind2 - 1))

# Test case
text1 = "abcde"
text2 = "ace"
print(longestCommonSubsequence(text1, text2, len(text1) - 1, len(text2) - 1))
