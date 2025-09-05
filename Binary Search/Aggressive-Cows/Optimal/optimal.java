import java.util.*;

public class optimal {
    // Function to check if we can place cows with at least 'dist' distance
    public static boolean canPlace(int[] stalls, int cows, int dist) {
        int count = 1;
        int lastPos = stalls[0];

        for (int i = 1; i < stalls.length; i++) {
            if (stalls[i] - lastPos >= dist) {
                count++;
                lastPos = stalls[i];
            }
            if (count >= cows) return true;
        }
        return false;
    }

    public static int aggressiveCows(int[] stalls, int cows) {
        Arrays.sort(stalls);
        int n = stalls.length;

        int low = 1, high = stalls[n - 1] - stalls[0];
        int ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canPlace(stalls, cows, mid)) {
                ans = mid;
                low = mid + 1; // Try bigger distance
            } else {
                high = mid - 1; // Try smaller distance
            }
        }
        return ans;
    }

    public static void main(String[] args) {
        int[] stalls = {1, 2, 8, 4, 9};
        int cows = 3;
        System.out.println("Maximum Minimum Distance: " + aggressiveCows(stalls, cows));
    }
}

/*
Time Complexity:
- Sorting: O(N log N)
- Binary Search: O(log(maxDistance))
- Placement Check: O(N) each iteration
Overall: O(N log N + N log(maxDistance))

Space Complexity: O(1)
*/

