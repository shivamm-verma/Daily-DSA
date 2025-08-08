public class RotatedSortedArraySearchWithPivot {

    public static int findPivot(int[] nums) {
        int left = 0, right = nums.length - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] > nums[right]) {
                left = mid + 1; // Pivot in right half
            } else {
                right = mid; // Pivot in left half or at mid
            }
        }
        return left; // Index of the smallest element (pivot)
    }

    public static int binarySearch(int[] nums, int left, int right, int target) {
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) return mid;
            else if (nums[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        return -1;
    }

    public static int search(int[] nums, int target) {
        if (nums.length == 0) return -1;

        int pivot = findPivot(nums);

        if (target >= nums[pivot] && target <= nums[nums.length - 1]) {
            return binarySearch(nums, pivot, nums.length - 1, target); // Right half
        } else {
            return binarySearch(nums, 0, pivot - 1, target); // Left half
        }
    }

    public static void main(String[] args) {
        int[] nums = {4, 5, 6, 7, 0, 1, 2};
        int target = 0;
        int result = search(nums, target);
        System.out.println("Index of target " + target + ": " + result); // Output: 4
    }
}
