class Solution:
    def maxArea(self, height):
        n = len(height)
        maxm = 0

        # Try every pair (i, j)
        for i in range(n):
            for j in range(i + 1, n):
                area = (j - i) * min(height[i], height[j])
                maxm = max(maxm, area)

        return maxm
