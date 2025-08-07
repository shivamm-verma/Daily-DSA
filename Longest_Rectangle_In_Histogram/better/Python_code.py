def largestRectangleArea(heights):
    n = len(heights)
    max_area = 0

    for i in range(n):
        left = i
        while left > 0 and heights[left - 1] >= heights[i]:
            left -= 1

        right = i
        while right < n - 1 and heights[right + 1] >= heights[i]:
            right += 1

        width = right - left + 1
        area = heights[i] * width
        max_area = max(max_area, area)

    return max_area
