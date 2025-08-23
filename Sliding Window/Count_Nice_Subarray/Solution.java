import java.util.*;

public class Solution {
    static int countAtMostK(int[] nums, int k) {
        int left = 0, odd = 0, count = 0;

        for (int right = 0; right < nums.length; right++) {
            if (nums[right] % 2 == 1) odd++;

            while (odd > k) {
                if (nums[left] % 2 == 1) odd--;
                left++;
            }
            count += right - left + 1;
        }
        return count;
    }

    static int numberOfSubarrays(int[] nums, int k) {
        return countAtMostK(nums, k) - countAtMostK(nums, k - 1);
    }

    public static void main(String[] args) {
        int[] nums = {1, 1, 2, 1, 1};
        int k = 3;
        System.out.println(numberOfSubarrays(nums, k));
    }
}
