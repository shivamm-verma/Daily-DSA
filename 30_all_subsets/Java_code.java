import java.util.*;
public class Java_code {
    public static void findSubsets(int[] nums, List<List<Integer>> result, List<Integer> current, int index) {
        result.add(new ArrayList<>(current));
        for (int i = index; i < nums.length; i++) {
            current.add(nums[i]);
            findSubsets(nums, result, current, i + 1);
            current.remove(current.size() - 1);
        }
    }
    public static List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        List<Integer> current = new ArrayList<>();
        findSubsets(nums, result, current, 0);
        return result;
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the size of array: ");
        int n = scanner.nextInt();
        int[] nums = new int[n];
        System.out.print("Enter " + n + " elements: ");
        for (int i = 0; i < n; i++) {
            nums[i] = scanner.nextInt();
        }
        List<List<Integer>> result = subsets(nums);
        System.out.println("All subsets:");
        for (List<Integer> subset : result) {
            System.out.print("[");
            for (int i = 0; i < subset.size(); i++) {
                System.out.print(subset.get(i));
                if (i < subset.size() - 1) System.out.print(", ");
            }
            System.out.println("]");
        }
        scanner.close();
    }
} 