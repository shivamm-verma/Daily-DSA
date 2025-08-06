import java.util.*;

public class BruteForce {
    // Function to check if Koko can eat all bananas at speed k within h hours
    public static boolean canFinish(int[] piles, int h, int k) {
        int totalHours = 0;
        for (int pile : piles) {
            // Ceil division: hours = ceil(pile / k)
            totalHours += (pile + k - 1) / k;  // same as Math.ceil((double)pile / k)
        }
        return totalHours <= h;
    }

   
    public static int minEatingSpeed(int[] piles, int h) {
        int max = 0;
        for (int pile : piles) {
            max = Math.max(max, pile);  
        }

        for (int k = 1; k <= max; k++) {
            if (canFinish(piles, h, k)) {
                return k;  
            }
        }

        return max;  
    }

 
    public static void main(String[] args) {
        int[] piles = {3, 6, 7, 11};
        int h = 8;
        int result = minEatingSpeed(piles, h);
        System.out.println("Minimum eating speed: " + result);  // Output: 4
    }
}
