import java.util.*;

public class code {
    public static String minWindowOptimal(String s, String t) {
        if (s.length() < t.length()) return "";

        int[] need = new int[128];
        int required = 0;
        for (char c : t.toCharArray()) {
            if (need[c] == 0) required++;
            need[c]++;
        }

        int[] window = new int[128];
        int formed = 0, l = 0, r = 0, minLen = Integer.MAX_VALUE, start = 0;

        while (r < s.length()) {
            char c = s.charAt(r);
            window[c]++;
            if (window[c] == need[c]) formed++;

            while (l <= r && formed == required) {
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    start = l;
                }
                char lc = s.charAt(l);
                window[lc]--;
                if (window[lc] < need[lc]) formed--;
                l++;
            }
            r++;
        }
        return minLen == Integer.MAX_VALUE ? "" : s.substring(start, start + minLen);
    }

    public static void main(String[] args) {
        String s = "ADOBECODEBANC", t = "ABC";
        System.out.println(minWindowOptimal(s, t)); // Expected: BANC
    }
}
