import java.util.*;

public class ThreeSumClosest {
    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int res = Integer.MAX_VALUE;
        for (int i = 0; i < nums.length - 2; i++) {
            int j = i + 1, k = nums.length - 1;
            while (j < k) {
                int total = nums[i] + nums[j] + nums[k];
                if (Math.abs(total - target) < Math.abs(res - target)) {
                    res = total;
                }
                if (total > target) {
                    k--;
                } else if (total < target) {
                    j++;
                } else {
                    return res;
                }
            }
        }
        return res;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter integers separated by spaces: ");
        String[] input = scanner.nextLine().split(" ");
        int[] nums = Arrays.stream(input).mapToInt(Integer::parseInt).toArray();

        System.out.print("Enter target integer: ");
        int target = scanner.nextInt();

        ThreeSumClosest solver = new ThreeSumClosest();
        int result = solver.threeSumClosest(nums, target);
        System.out.println("The sum closest to the target is: " + result);
    }
}
