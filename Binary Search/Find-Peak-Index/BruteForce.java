
public class BruteForce {
    public static int findPeakElement(int[] nums) {
        int n = nums.length;

        for (int i = 0; i < n; i++) {
            // Check left neighbor (if exists)
            boolean left = (i == 0) || (nums[i] > nums[i - 1]);
            // Check right neighbor (if exists)
            boolean right = (i == n - 1) || (nums[i] > nums[i + 1]);

            if (left && right) {
                return i;
            }
        }

        return -1; // should never happen due to problem constraints
    }
    public static void main(String[] args) {
        int[] nums1 = {1, 2, 3, 1};
        int[] nums2 = {1, 2, 1, 3, 5, 6, 4};

        System.out.println("Peak index in nums1: " + findPeakElement(nums1)); // Expected: 2
        System.out.println("Peak index in nums2: " + findPeakElement(nums2)); // Expected: 1 or 5
    }
}
