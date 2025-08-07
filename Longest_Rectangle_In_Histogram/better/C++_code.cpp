int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    int maxArea = 0;

    for (int i = 0; i < n; ++i) {
        int left = i, right = i;

        // Find nearest smaller to left
        while (left > 0 && heights[left - 1] >= heights[i]) left--;

        // Find nearest smaller to right
        while (right < n - 1 && heights[right + 1] >= heights[i]) right++;

        int width = right - left + 1;
        int area = heights[i] * width;
        maxArea = max(maxArea, area);
    }

    return maxArea;
}
