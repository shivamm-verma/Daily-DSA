class Solution {
    public int collecting_Water(int[] heights) {
        int n = heights.length;
        if (n <= 2) {
            return 0;
        }
        
        int left = 0, right = n - 1;
        int leftMax = 0, rightMax = 0;
        int totalWater = 0;
        
        while (left < right) {
            if (heights[left] < heights[right]) {
                if (heights[left] >= leftMax) {
                    leftMax = heights[left];
                } else {
                    totalWater += leftMax - heights[left];
                }
                left++;
            } else {
                if (heights[right] >= rightMax) {
                    rightMax = heights[right];
                } else {
                    totalWater += rightMax - heights[right];
                }
                right--;
            }
        }
        
        return totalWater;
    }
}