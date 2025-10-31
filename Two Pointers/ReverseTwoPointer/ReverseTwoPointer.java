// Hacktoberfest Contribution
// Topic: Two Pointers
// Problem: Reverse an array using the two-pointer technique

public class ReverseTwoPointer {

    public static void reverseArray(int[] arr) {
        int left = 0, right = arr.length - 1;
        while (left < right) {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            left++;
            right--;
        }
    }

    public static void main(String[] args) {
        int[] nums = {1, 2, 3, 4, 5};
        reverseArray(nums);

        System.out.print("Reversed Array: ");
        for (int n : nums) {
            System.out.print(n + " ");
        }
    }
}
