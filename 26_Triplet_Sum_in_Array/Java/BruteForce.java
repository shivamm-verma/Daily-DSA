public class BruteForce {

    // Function to check if any triplet sums up to the target
    public static boolean hasTripletSum(int[] arr, int target) {
        int n = arr.length;

        // Check all possible triplets
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (arr[i] + arr[j] + arr[k] == target) {
                        return true;
                    }
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
Time Complexity: O(n³)

Space Complexity: O(1)

This code is ideal for small input sizes or learning purposes.

 */
