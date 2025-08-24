class Solution:
    def solveRec(self, s: str, p: str, i: int, j: int) -> bool:
        if i == len(s) and j == len(p):
            return True
        if j == len(p):
            return False

        curr_match = (i < len(s)) and (p[j] == '.' or s[i] == p[j])

        if j + 1 < len(p) and p[j + 1] == '*':
            empty_case = self.solveRec(s, p, i, j + 2)
            prec_element_case = curr_match and self.solveRec(s, p, i + 1, j)
            return empty_case or prec_element_case
        elif curr_match:
            return self.solveRec(s, p, i + 1, j + 1)
        else:
            return False

    def isMatch(self, s: str, p: str) -> bool:
        return self.solveRec(s, p, 0, 0)

# Main execution block
if __name__ == "__main__":
    sol = Solution()
    s = "mississippi"
    p = "mis*is*p*."
    print(f'Input String: "{s}", Pattern: "{p}"')
    print(f'Output: {sol.isMatch(s, p)}')
