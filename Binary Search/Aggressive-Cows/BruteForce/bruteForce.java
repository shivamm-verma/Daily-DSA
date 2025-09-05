import java.util.*;

public class bruteForce {
    static boolean canPlace(int[] stalls, int cows, int dist) {
        int count = 1, last = stalls[0];
        for (int i = 1; i < stalls.length; i++) {
            if (stalls[i] - last >= dist) {
                count++;
                last = stalls[i];
            }
            if (count >= cows) return true;
        }
        return false;
    }

    static int aggressiveCows(int[] stalls, int cows) {
        Arrays.sort(stalls);
        int ans = 0;
        
        for (int dist = 1; dist <= stalls[stalls.length - 1] - stalls[0]; dist++) {
            if (canPlace(stalls, cows, dist)) {
                ans = dist;
            }
        }
        return ans;
    }

    public static void main(String[] args) {
        int[] stalls = {1, 2, 8, 4, 9};
        int cows = 3;
        System.out.println(aggressiveCows(stalls, cows));
    }
}

/*
Time Complexity: O(N * (max(stall) - min(stall)))  
Space Complexity: O(1)
*/

