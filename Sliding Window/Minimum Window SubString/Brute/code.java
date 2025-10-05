import java.util.*;

public class code {
    public static boolean containsAll(String sub, String t) {
        int[] count = new int[128];
        for (char c : sub.toCharArray()) count[c]++;
        for (char c : t.toCharArray()) {
            if (--count[c] < 0) return false;
        }
        return true;
    }

    public static String minWindowBrute(String s, String t) {
        int n = s.length();
        String ans = "";
        int minLen = Integer.MAX_VALUE;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                String sub = s.substring(i, j + 1);
                if (containsAll(sub, t) && sub.length() < minLen) {
                    ans = sub;
                    minLen = sub.length();
                }
            }
        }
        return ans;
    }

    public static void main(String[] args) {
        String s = "ADOBECODEBANC", t = "ABC";
        System.out.println(minWindowBrute(s, t)); // Expected: BANC
    }
}
