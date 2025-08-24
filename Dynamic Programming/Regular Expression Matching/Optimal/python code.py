class Solution:
    def solveTab(self, s: str, p: str, m: int, n: int) -> bool:
        dp = [[False] * (n + 1) for _ in range(m + 1)]
        dp[m][n] = True

        for i in range(m, -1, -1):
            for j in range(n - 1, -1, -1):
                curr_match = (i < m) and (p[j] == '.' or s[i] == p[j])
                if j + 1 < n and p[j + 1] == '*':
                    dp[i][j] = dp[i][j + 2] or (curr_match and dp[i + 1][j])
                elif curr_match:
                    dp[i][j] = dp[i + 1][j + 1]
                else:
                    dp[i][j] = False
        
        return dp[0][0]

    def isMatch(self, s: str, p: str) -> bool:
        return self.solveTab(s, p, len(s), len(p))

# Main execution block
if __name__ == "__main__":
    sol = Solution()
    s = "mississippi"
    p = "mis*is*p*."
    print(f'Input String: "{s}", Pattern: "{p}"')
    print(f'Output: {sol.isMatch(s, p)}')
