// BruteForce.java

public class BruteForce {
    public static int maxSubarraySum(int[] arr) {
        int n = arr.length;
        int maxSum = Integer.MIN_VALUE;

        // Outer loop to pick starting index
        for (int i = 0; i < n; i++) {
            int currSum = 0;

            // Inner loop to pick ending index
            for (int j = i; j < n; j++) {
                currSum += arr[j];
                maxSum = Math.max(maxSum, currSum);
            }
        }

        return maxSum;
    }

    public static void main(String[] args) {
        int[] arr = {2, 3, -8, 7, -1, 2, 3};
        System.out.println("Maximum Subarray Sum (Brute Force): " + maxSubarraySum(arr));
    }
}

/*
Time Complexity: O(n^2)
Space Complexity: O(1)
*/
