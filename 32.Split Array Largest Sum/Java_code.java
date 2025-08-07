import java.util.Scanner;
class Solution {

    public static boolean isPossible(int[] nums, int k, int min) {
        int sum = 0;

        for (int i = 0; i < nums.length; i++) {
            if (nums[i] > min) return false;

            if (sum + nums[i] > min) {
                k = k - 1;
                sum = 0;
            }
            sum = sum + nums[i];

            if (k <= 0) return false;
        }

        return true;
    }

    public int splitArray(int[] nums, int k) {
        int l = 0;
        int r = (int) Math.pow(10, 9);
        int res = 0;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (isPossible(nums, k, mid)) {
                res = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return res;
    }

    
    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] nums = {7, 2, 5, 10, 8};
        int k = 2;

        int result = sol.splitArray(nums, k);
        System.out.println("Minimized Largest Sum: " + result); // Output: 18
    }
}
