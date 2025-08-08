int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    vector<int> left(n), right(n, n);
    stack<int> st;

    // Previous smaller (NSL)
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && heights[st.top()] >= heights[i]) st.pop();
        left[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }

    // Clear stack for next pass
    while (!st.empty()) st.pop();

    // Next smaller (NSR)
    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && heights[st.top()] >= heights[i]) st.pop();
        right[i] = st.empty() ? n : st.top();
        st.push(i);
    }

    int maxArea = 0;
    for (int i = 0; i < n; ++i) {
        int width = right[i] - left[i] - 1;
        maxArea = max(maxArea, heights[i] * width);
    }

    return maxArea;
}
