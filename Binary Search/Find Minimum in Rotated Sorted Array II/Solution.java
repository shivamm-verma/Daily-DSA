import java.util.*;

class Solution {
    public int findMin(int[] nums) {
        int lo = 0, hi = nums.length - 1;

        // If array is not rotated
        if (nums[lo] < nums[hi]) {
            return nums[lo];
        }

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;

            if (nums[mid] > nums[hi]) {
                lo = mid + 1;
            } 
            else if (nums[mid] > nums[lo]) {
                hi = mid;
            } 
            else {
                hi--;
            }
        }
        return nums[lo];
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        // Input array size
        System.out.print("Enter number of elements: ");
        int n = sc.nextInt();
        
        int[] nums = new int[n];
        System.out.println("Enter array elements:");
        for (int i = 0; i < n; i++) {
            nums[i] = sc.nextInt();
        }

        Solution sol = new Solution();
        int min = sol.findMin(nums);
        System.out.println("Minimum element in rotated array: " + min);
    }
}
