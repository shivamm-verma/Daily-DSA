class Solution:
    def expandAroundCenter(self, s: str, left: int, right: int) -> str:
        while left >= 0 and right < len(s) and s[left] == s[right]:
            left -= 1
            right += 1
        return s[left + 1:right]

    def longestPalindrome(self, s: str) -> str:
        longest = ""
        for i in range(len(s)):
            odd = self.expandAroundCenter(s, i, i)       # Odd length
            even = self.expandAroundCenter(s, i, i + 1)  # Even length

            candidate = odd if len(odd) > len(even) else even
            if len(candidate) > len(longest):
                longest = candidate
        return longest


# Example usage
sol = Solution()
print(sol.longestPalindrome("babad"))  # "bab" or "aba"
print(sol.longestPalindrome("cbbd"))   # "bb"
