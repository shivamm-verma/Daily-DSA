class Solution:
    def maxArea(self, height):
        left, right = 0, len(height) - 1
        maxm = 0

        while left < right:
            area = (right - left) * min(height[left], height[right])
            maxm = max(maxm, area)

            # Move the smaller height pointer
            if height[left] < height[right]:
                left += 1
            else:
                right -= 1

        return maxm
