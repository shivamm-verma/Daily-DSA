import java.util.HashSet;

public class Better {

    // Function to check if any triplet sums up to the target using hashing
    public static boolean hasTripletSum(int[] arr, int target) {
        int n = arr.length;

        // Fix the first element one by one
        for (int i = 0; i < n - 2; i++) {
            HashSet<Integer> set = new HashSet<>();

            // Now look for a pair (arr[j], x) such that arr[i] + arr[j] + x = target
            for (int j = i + 1; j < n; j++) {
                int required = target - arr[i] - arr[j];

                if (set.contains(required)) {
                    return true;
                }

                // Add current element to the set for future pairs
                set.add(arr[j]);
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

Space Complexity: O(n)

This is faster than brute force and works well on moderately large input arrays. */
