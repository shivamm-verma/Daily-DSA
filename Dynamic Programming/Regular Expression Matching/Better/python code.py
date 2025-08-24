class Solution:
    def __init__(self):
        self.dp = {}

    def solveMem(self, s: str, p: str, i: int, j: int) -> bool:
        if (i, j) in self.dp:
            return self.dp[(i, j)]
        
        if i == len(s) and j == len(p):
            return True
        if j == len(p):
            return False

        curr_match = (i < len(s)) and (p[j] == '.' or s[i] == p[j])
        ans = False

        if j + 1 < len(p) and p[j + 1] == '*':
            empty_case = self.solveMem(s, p, i, j + 2)
            prec_element_case = curr_match and self.solveMem(s, p, i + 1, j)
            ans = empty_case or prec_element_case
        elif curr_match:
            ans = self.solveMem(s, p, i + 1, j + 1)
        
        self.dp[(i, j)] = ans
        return ans

    def isMatch(self, s: str, p: str) -> bool:
        self.dp = {}
        return self.solveMem(s, p, 0, 0)

# Main execution block
if __name__ == "__main__":
    sol = Solution()
    s = "mississippi"
    p = "mis*is*p*."
    print(f'Input String: "{s}", Pattern: "{p}"')
    print(f'Output: {sol.isMatch(s, p)}')
