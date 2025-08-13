import java.util.*;

public class Main {

    public static int countPartitions(int[] a, int maxSum) {
        int partitions = 1;
        long subarraySum = 0;

        for (int num : a) {
            if (subarraySum + num <= maxSum) {
                subarraySum += num;
            } else {
                partitions++;
                subarraySum = num;
            }
        }
        return partitions;
    }

    public static int largestSubarraySumMinimized(int[] a, int k) {
        int low = Arrays.stream(a).max().getAsInt();
        int high = Arrays.stream(a).sum();

        for (int maxSum = low; maxSum <= high; maxSum++) {
            if (countPartitions(a, maxSum) == k)
                return maxSum;
        }
        return low;
    }

    public static void main(String[] args) {
        int[] a = {10, 20, 30, 40};
        int k = 2;
        int ans = largestSubarraySumMinimized(a, k);
        System.out.println("The answer is: " + ans);
    }
}
