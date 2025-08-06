import java.util.Arrays;

public class Optimised {

    // Function to check if any triplet sums up to the target using sorting + two-pointer
    public static boolean hasTripletSum(int[] arr, int target) {
        int n = arr.length;

        // Sort the array to apply two-pointer technique
        Arrays.sort(arr);

        // Fix the first element and apply two-pointer on the rest
        for (int i = 0; i < n - 2; i++) {
            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int sum = arr[i] + arr[left] + arr[right];

                if (sum == target) {
                    return true;
                } else if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }

        return false;
    }

    public static void main(String[] args) {
        // Sample input
        int[] arr = {1, 4, 45, 6, 10, 8};
        int target = 13;

        // Function call
        if (hasTripletSum(arr, target)) {
            System.out.println("true");
        } else {
            System.out.println("false");
        }
    }
}

/* 💡 Notes:
Time Complexity: O(n²)

Space Complexity: O(1)

Most suitable for large arrays and optimal for real-world use. */

