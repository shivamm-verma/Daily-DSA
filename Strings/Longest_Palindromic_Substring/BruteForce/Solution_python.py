class Solution:
    def longestPalindromeBrute(self, s: str) -> str:
        n = len(s)
        longest = ""

        def isPalindrome(l, r):
            while l < r:
                if s[l] != s[r]:
                    return False
                l += 1
                r -= 1
            return True

        for i in range(n):
            for j in range(i, n):
                if isPalindrome(i, j):
                    if j - i + 1 > len(longest):
                        longest = s[i:j+1]
        return longest


# Example usage
sol = Solution()
print(sol.longestPalindromeBrute("babad"))  # "bab" or "aba"
print(sol.longestPalindromeBrute("cbbd"))   # "bb"
