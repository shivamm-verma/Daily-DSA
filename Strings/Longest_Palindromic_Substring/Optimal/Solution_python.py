class Solution:
    def longestPalindrome(self, s: str) -> str:
        if not s:
            return ""
        
        # Transform string
        T = "^"
        for c in s:
            T += "#" + c
        T += "#$"
        
        n = len(T)
        P = [0] * n
        center = right = 0
        
        for i in range(1, n - 1):
            mirror = 2 * center - i
            
            if i < right:
                P[i] = min(right - i, P[mirror])
            
            # Expand around center
            while T[i + (1 + P[i])] == T[i - (1 + P[i])]:
                P[i] += 1
            
            # Update center & right
            if i + P[i] > right:
                center = i
                right = i + P[i]
        
        # Find max length palindrome
        maxLen = 0
        centerIndex = 0
        for i in range(1, n - 1):
            if P[i] > maxLen:
                maxLen = P[i]
                centerIndex = i
        
        start = (centerIndex - maxLen) // 2
        return s[start:start + maxLen]


# Example usage
sol = Solution()
print(sol.longestPalindrome("babad"))  # "bab" or "aba"
print(sol.longestPalindrome("cbbd"))   # "bb"
