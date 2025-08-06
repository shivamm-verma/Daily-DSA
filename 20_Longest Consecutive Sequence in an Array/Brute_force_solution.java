//import java.util.*;

class Solution {
    // Helper function to perform linear search
    private boolean linearSearch(int[] a, int num) {
        int n = a.length;
        // Traverse through the array
        for (int i = 0; i < n; i++) {
            if (a[i] == num)
                return true;
        }
        return false;
    }

    public int longestConsecutive(int[] nums) {
        // If the array is empty
        if (nums.length == 0) {
            return 0;
        }
        int n = nums.length;
        // Initialize the longest sequence length
        int longest = 1;

        // Iterate through each element in the array
        for (int i = 0; i < n; i++) {
            // Current element
            int x = nums[i];
            // Count of the current sequence
            int cnt = 1;

            // Search for consecutive numbers
            while (linearSearch(nums, x + 1) == true) {
                // Move to the next number in the sequence
                x += 1;
                // Increment the count of the sequence
                cnt += 1;
            }

            // Update the longest sequence length found so far
            longest = Math.max(longest, cnt);
        }
        return longest;
    }

    public static void main(String[] args) {
        int[] a = {100, 4, 200, 1, 3, 2};

        // Create an instance of the Solution class
        Solution solution = new Solution();

        // Function call for longest consecutive sequence
        int ans = solution.longestConsecutive(a);
        System.out.println("The longest consecutive sequence is " + ans);
    }
}
