class Solution:
    def solveTabSO(self, s: str, p: str, m: int, n: int) -> bool:
        prev = [False] * (n + 1)
        curr = [False] * (n + 1)
        prev[n] = True

        for i in range(m, -1, -1):
            curr[n] = (i == m)
            for j in range(n - 1, -1, -1):
                first_match = (i < m and (p[j] == s[i] or p[j] == '.'))
                if j + 1 < n and p[j + 1] == '*':
                    curr[j] = curr[j + 2] or (first_match and prev[j])
                else:
                    curr[j] = first_match and prev[j + 1]
            prev = list(curr)
        
        return prev[0]

    def isMatch(self, s: str, p: str) -> bool:
        return self.solveTabSO(s, p, len(s), len(p))

# Main execution block
if __name__ == "__main__":
    sol = Solution()
    s = "mississippi"
    p = "mis*is*p*."
    print(f'Input String: "{s}", Pattern: "{p}"')
    print(f'Output: {sol.isMatch(s, p)}')

