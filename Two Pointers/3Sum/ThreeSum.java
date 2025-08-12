import java.util.*;

public class ThreeSum {
    public static List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> res = new ArrayList<>();

        for (int i = 0; i < nums.length - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int j = i + 1, k = nums.length - 1;
            while (j < k) {
                int total = nums[i] + nums[j] + nums[k];
                if (total == 0) {
                    res.add(Arrays.asList(nums[i], nums[j], nums[k]));
                    j++;
                    k--;
                    while (j < k && nums[j] == nums[j - 1]) j++;
                    while (j < k && nums[k] == nums[k + 1]) k--;
                } else if (total < 0) {
                    j++;
                } else {
                    k--;
                }
            }
        }

        return res;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        List<Integer> inputList = new ArrayList<>();
        System.out.println("Enter integers separated by spaces:");

        while (sc.hasNextInt()) {
            inputList.add(sc.nextInt());
        }

        int[] nums = inputList.stream().mapToInt(i -> i).toArray();
        List<List<Integer>> result = threeSum(nums);

        System.out.println("\nUnique triplets that sum to zero :");
        for (List<Integer> triplet : result) {
            System.out.println(triplet);
        }
    }
}
