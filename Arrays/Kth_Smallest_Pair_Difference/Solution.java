import java.util.Arrays;
import java.util.Scanner;

public class Solution {

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

    public static int smallestDistancePair(int[] nums, int k) {
        Arrays.sort(nums);
        int left = 0, right = nums[nums.length - 1] - nums[0];

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (countPairs(nums, mid) >= k) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number of elements: ");
        int n = sc.nextInt();
        int[] nums = new int[n];
        System.out.print("Enter the elements: ");
        for (int i = 0; i < n; i++) nums[i] = sc.nextInt();
        System.out.print("Enter k: ");
        int k = sc.nextInt();

        System.out.println("Kth Smallest Pair Difference: " + smallestDistancePair(nums, k));
        sc.close();
    }
}
