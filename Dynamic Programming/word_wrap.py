import sys

class Solution:
    def solveWordWrap(self, arr, k):
        n = len(arr)
        dp = [0] * n
        ans = [0] * n
        dp[n - 1] = 0
        ans[n - 1] = n - 1

       
        for i in range(n - 2, -1, -1):
            currlen = -1
            dp[i] = sys.maxsize
            for j in range(i, n):
                currlen += arr[j] + 1
                if currlen > k:
                    break
                if j == n - 1:
                    cost = 0
                else:
                    cost = (k - currlen) * (k - currlen) + dp[j + 1]
                if cost < dp[i]:
                    dp[i] = cost
                    ans[i] = j

      
        i = 0
        res = 0
        while i < n:
            pos = 0
            for j in range(i, ans[i] + 1):
                pos += arr[j]
            x = ans[i] - i
            if ans[i] + 1 != n:
                res += (k - x - pos) ** 2
            i = ans[i] + 1
        return res


if __name__ == "__main__":
    n = int(input())
    arr = list(map(int, input().split()))
    k = int(input())
    sol = Solution()
    print(sol.solveWordWrap(arr, k))
