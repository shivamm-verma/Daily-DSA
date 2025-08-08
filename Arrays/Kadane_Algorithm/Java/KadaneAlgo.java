// Optimised.java

public class KadaneAlgo {
    public static int maxSubarraySum(int[] arr) {
        int n = arr.length;

        int maxEndingHere = arr[0];
        int maxSoFar = arr[0];

        for (int i = 1; i < n; i++) {
            // Either extend the previous subarray or start a new one
            maxEndingHere = Math.max(arr[i], maxEndingHere + arr[i]);
            maxSoFar = Math.max(maxSoFar, maxEndingHere);
        }

        return maxSoFar;
    }

    public static void main(String[] args) {
        int[] arr = {2, 3, -8, 7, -1, 2, 3};
        System.out.println("Maximum Subarray Sum (Kadane's Algorithm): " + maxSubarraySum(arr));
    }
}

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/

