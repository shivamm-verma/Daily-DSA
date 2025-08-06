public int largestRectangleArea(int[] heights) {
    Stack<Integer> stack = new Stack<>();
    int maxArea = 0;
    int[] extended = Arrays.copyOf(heights, heights.length + 1);

    for (int i = 0; i < extended.length; i++) {
        while (!stack.isEmpty() && extended[i] < extended[stack.peek()]) {
            int height = extended[stack.pop()];
            int width = stack.isEmpty() ? i : i - stack.peek() - 1;
            maxArea = Math.max(maxArea, height * width);
        }
        stack.push(i);
    }

    return maxArea;
}
