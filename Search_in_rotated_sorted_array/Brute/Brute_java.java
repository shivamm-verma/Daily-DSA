public class LinearSearchRotatedArray {

    public static int search(int[] nums, int target) {
        // Linear search through the array
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == target) {
                return i;
            }
        }
        return -1; // Target not found
    }

    public static void main(String[] args) {
        int[] nums = {4, 5, 6, 7, 0, 1, 2};
        int target = 0;
        int result = search(nums, target);
        System.out.println("Index of target " + target + ": " + result); // Output: 4
    }
}
