import java.util.Arrays;

class Solution {
    public int[] productExceptSelf(int[] nums) {
        int n = nums.length;
        int[] answer = new int[n];

        // Step 1: Prefix product
        int prefix = 1;
        for (int i = 0; i < n; i++) {
            answer[i] = prefix;
            prefix *= nums[i];
        }

        // Step 2: Suffix product
        int suffix = 1;
        for (int i = n - 1; i >= 0; i--) {
            answer[i] *= suffix;
            suffix *= nums[i];
        }

        return answer;
    }

    // Example usage
    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] nums = {1, 2, 3, 4};
        int[] result = sol.productExceptSelf(nums);

        System.out.println(Arrays.toString(result)); // Output: [24, 12, 8, 6]
    }
}
