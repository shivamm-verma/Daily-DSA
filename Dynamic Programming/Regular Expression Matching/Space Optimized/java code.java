import java.util.Arrays;

class Solution {
    public boolean solveTabSO(String s, String p, int m, int n) {
        boolean[] prev = new boolean[n + 1];
        boolean[] curr = new boolean[n + 1];
        prev[n] = true;

        for (int i = m; i >= 0; --i) {
            curr[n] = (i == m);
            for (int j = n - 1; j >= 0; --j) {
                boolean first_match = (i < m && (p.charAt(j) == s.charAt(i) || p.charAt(j) == '.'));
                if (j + 1 < n && p.charAt(j + 1) == '*') {
                    curr[j] = curr[j + 2] || (first_match && prev[j]);
                } else {
                    curr[j] = first_match && prev[j + 1];
                }
            }
            // System.arraycopy(curr, 0, prev, 0, n + 1);
            prev = curr.clone();
        }
        return prev[0];
    }

    public boolean isMatch(String s, String p) {
        return solveTabSO(s, p, s.length(), p.length());
    }
}

public class Main {
    public static void main(String[] args) {
        Solution sol = new Solution();
        String s = "mississippi";
        String p = "mis*is*p*.";
        System.out.println("Input String: \"" + s + "\", Pattern: \"" + p + "\"");
        System.out.println("Output: " + sol.isMatch(s, p));
    }
}
