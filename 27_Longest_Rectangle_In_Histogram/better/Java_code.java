public int largestRectangleArea(int[] heights) {
    int n = heights.length, maxArea = 0;

    for (int i = 0; i < n; i++) {
        int left = i, right = i;

        // Nearest Smaller to Left
        while (left > 0 && heights[left - 1] >= heights[i]) left--;

        // Nearest Smaller to Right
        while (right < n - 1 && heights[right + 1] >= heights[i]) right++;

        int width = right - left + 1;
        int area = heights[i] * width;
        maxArea = Math.max(maxArea, area);
    }

    return maxArea;
}
