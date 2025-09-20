import java.util.*;

public class code {
    private static boolean allCovered(int[] need) {
        for (int x : need) if (x > 0) return false;
        return true;
    }

    public static String minWindowBetter(String s, String t) {
        int n = s.length(), minLen = Integer.MAX_VALUE;
        String ans = "";

        for (int i = 0; i < n; i++) {
            int[] need = new int[128];
            for (char c : t.toCharArray()) need[c]++;
            for (int j = i; j < n; j++) {
                char c = s.charAt(j);
                if (need[c] > 0) need[c]--;
                if (allCovered(need)) {
                    if (j - i + 1 < minLen) {
                        ans = s.substring(i, j + 1);
                        minLen = j - i + 1;
                    }
                    break;
                }
            }
        }
        return ans;
    }

    public static void main(String[] args) {
        String s = "ADOBECODEBANC", t = "ABC";
        System.out.println(minWindowBetter(s, t)); // Expected: BANC
    }
}
