class Solution {
    public int maxArea(int[] height) {
        int n = height.length;
        int maxm = 0;

        // Try every pair (i, j)
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int area = (j - i) * Math.min(height[i], height[j]);
                maxm = Math.max(maxm, area);
            }
        }
        return maxm;
    }
}
