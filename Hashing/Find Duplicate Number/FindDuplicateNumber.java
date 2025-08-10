import java.util.*;

public class FindDuplicateNumber {
    public static int findDuplicate(int[] nums) {
        Set<Integer> seen = new HashSet<>();
        for (int num : nums) {
            if (!seen.add(num)) {
                return num;
            }
        }
        return -1; // Return -1 if no duplicate found 
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the number of elements: ");
        int n = sc.nextInt();

        int[] nums = new int[n];
        System.out.println("Enter the elements (one duplicate expected):");
        for (int i = 0; i < n; i++) {
            nums[i] = sc.nextInt();
        }

        int duplicate = findDuplicate(nums);
        System.out.println("Duplicate number is: " + duplicate);
    }
}
