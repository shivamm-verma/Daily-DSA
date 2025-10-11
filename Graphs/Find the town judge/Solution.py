class Solution:
    def findJudge(self, n: int, trust: list[list[int]]) -> int:
        outdegree = [0] * (n + 1)
        indegree = [0] * (n + 1)

        for a, b in trust:
            outdegree[a] += 1
            indegree[b] += 1

        for i in range(1, n + 1):
            if outdegree[i] == 0 and indegree[i] == n - 1:
                return i

        return -1

# Example run
if __name__ == "__main__":
    sol = Solution()
    n = 3
    trust = [[1, 3], [2, 3]]
    print(sol.findJudge(n, trust))  # Output: 3
