public int largestRectangleArea(int[] heights) {
    int n = heights.length;
    int maxArea = 0;

    for (int i = 0; i < n; i++) {
        int height = heights[i];

        // Expand to the left
        int left = i;
        while (left > 0 && heights[left - 1] >= height) {
            left--;
        }

        // Expand to the right
        int right = i;
        while (right < n - 1 && heights[right + 1] >= height) {
            right++;
        }

        // Calculate area
        int width = right - left + 1;
        int area = height * width;
        maxArea = Math.max(maxArea, area);
    }

    return maxArea;
}
