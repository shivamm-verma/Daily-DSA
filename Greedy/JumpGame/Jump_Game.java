// Greedy approach: track furthest reachable index.
// Time: O(n), Space: O(1)
class Solution {
    public boolean canJump(int[] nums) {
        int maxReach = 0;
        int n = nums.length;

        for (int i = 0; i < n; i++) {
            if (i > maxReach) return false;
            maxReach = Math.max(maxReach, i + nums[i]);
            if (maxReach >= n - 1) return true;
        }
        return true;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        System.out.println(solution.canJump(new int[]{2, 3, 1, 1, 4})); // true
        System.out.println(solution.canJump(new int[]{3, 2, 1, 0, 4})); // false
    }
}