import java.util.Arrays;
import java.util.Scanner;

public class Solution {

    // Function to count the number of pairs with difference <= mid
    private static int countPairs(int[] nums, int mid) {
        int count = 0, left = 0;
        for (int right = 0; right < nums.length; right++) {
            while (nums[right] - nums[left] > mid) {
                left++;
            }
            count += right - left;
        }
        return count;
    }

    // Function to find Kth smallest pair difference
    public static int smallestDistancePair(int[] nums, int k) {
        /*
        Approach:
        1. Sort the array
        2. Binary search on the possible difference values (0 to max-min)
        3. For each mid, count pairs with difference <= mid using two pointers
        4. Narrow the search space based on the count

        Time Complexity: O(n log W), where W = max(nums) - min(nums)
        Space Complexity: O(1)
        */
        Arrays.sort(nums); // Step 1: Sort the array
        int left = 0, right = nums[nums.length - 1] - nums[0];

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (countPairs(nums, mid) >= k) right = mid;
            else left = mid + 1;
        }
        return left;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Interactive input
        System.out.print("Enter number of elements and k: ");
        int n = sc.nextInt();
        int k = sc.nextInt();

        int[] arr = new int[n];
        System.out.print("Enter " + n + " numbers: ");
        for (int i = 0; i < n; i++) arr[i] = sc.nextInt();

        System.out.println("Kth Smallest Pair Difference: " + smallestDistancePair(arr, k));
        sc.close();
    }
}
