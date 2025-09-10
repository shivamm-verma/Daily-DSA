import java.util.*;

public class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        Arrays.sort(nums);
        List<List<Integer>> a = new ArrayList<>();
        for (int i = 0; i < nums.length - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < nums.length - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                int l = j + 1;
                int k = nums.length - 1;
                while (l < k) {
                    long total = (long) nums[i] + nums[j] + nums[l] + nums[k];
                    if (total == target) {
                        a.add(Arrays.asList(nums[i], nums[j], nums[l], nums[k]));
                        l++;
                        k--;
                        while (l < k && nums[l] == nums[l - 1]) l++;
                        while (l < k && nums[k] == nums[k + 1]) k--;
                    } else if (total > target) {
                        k--;
                    } else {
                        l++;
                    }
                }
            }
        }
        return a;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Input array size
        System.out.print("Enter number of elements: ");
        int n = sc.nextInt();

        // Input array elements
        int[] nums = new int[n];
        System.out.println("Enter array elements:");
        for (int i = 0; i < n; i++) {
            nums[i] = sc.nextInt();
        }

        // Input target
        System.out.print("Enter target sum: ");
        int target = sc.nextInt();

        // Call fourSum
        Solution sol = new Solution();
        List<List<Integer>> result = sol.fourSum(nums, target);

        // Output result
        System.out.println("Quadruplets that sum to target:");
        for (List<Integer> quad : result) {
            System.out.println(quad);
        }

        sc.close();
    }
}
