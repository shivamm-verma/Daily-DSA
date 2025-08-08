import java.util.*;

class Solution {
    public int longestConsecutive(int[] nums) {
        int n = nums.length;
        // If the array is empty
        if (n == 0) return 0;

        // Initialize the longest sequence length
        int longest = 1; 
        Set<Integer> st = new HashSet<>();

        // Put all the array elements into the set
        for (int i = 0; i < n; i++) {
            st.add(nums[i]);
        }

        /* Traverse the set to 
           find the longest sequence */
        for (int it : st) {
            // Check if 'it' is a starting number of a sequence
            if (!st.contains(it - 1)) {
                // Initialize the count of the current sequence
                int cnt = 1; 
                // Starting element of the sequence
                int x = it; 

                // Find consecutive numbers in the set
                while (st.contains(x + 1)) {
                    // Move to the next element in the sequence
                    x = x + 1; 
                    // Increment the count of the sequence
                    cnt = cnt + 1; 
                }
                // Update the longest sequence length
                longest = Math.max(longest, cnt);
            }
        }
        return longest;
    }

    public static void main(String[] args) {
        int[] a = {100, 4, 200, 1, 3, 2}; 
        // Create an instance of the solution class
        Solution solution = new Solution(); 
        // Function call to find the longest consecutive sequence
        int ans = solution.longestConsecutive(a); 
        System.out.println("The longest consecutive sequence is " + ans); 
    }
}
