import java.util.*;

public class Optimal {

    // Function to check if Koko can finish all bananas at speed k within h hours
    public static boolean canFinish(int[] piles, int h, int k) {
        int totalHours = 0;
        for (int pile : piles) {
            totalHours += (pile + k - 1) / k;  // Ceil division
        }
        return totalHours <= h;
    }

    public static int minEatingSpeed(int[] piles, int h) {
        int low = 1;
        int high = Arrays.stream(piles).max().getAsInt();  

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (canFinish(piles, h, mid)) {
                high = mid;  
            } else {
                low = mid + 1;  
            }
        }

        return low;
    }

   
    public static void main(String[] args) {
        int[] piles = {3, 6, 7, 11};
        int h = 8;
        int result = minEatingSpeed(piles, h);
        System.out.println("Minimum eating speed: " + result);  // Output: 4
    }
}

