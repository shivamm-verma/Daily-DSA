def largestRectangleArea(heights):
    n = len(heights)
    max_area = 0

    for i in range(n):
        height = heights[i]

        # Expand to the left
        left = i
        while left > 0 and heights[left - 1] >= height:
            left -= 1

        # Expand to the right
        right = i
        while right < n - 1 and heights[right + 1] >= height:
            right += 1

        # Calculate area
        width = right - left + 1
        area = height * width
        max_area = max(max_area, area)

    return max_area
