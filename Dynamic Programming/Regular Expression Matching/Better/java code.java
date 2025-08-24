import java.util.Arrays;

class SolutionMemoization {
    private Boolean[][] dp;

    private boolean solveMem(String s, String p, int i, int j) {
        if (i == s.length() && j == p.length()) {
            return true;
        }
        if (j == p.length()) {
            return false;
        }
        if (dp[i][j] != null) {
            return dp[i][j];
        }

        boolean currMatch = (i < s.length()) && (p.charAt(j) == '.' || s.charAt(i) == p.charAt(j));
        boolean ans;

        if (j + 1 < p.length() && p.charAt(j + 1) == '*') {
            boolean emptyCase = solveMem(s, p, i, j + 2);
            boolean precElementCase = currMatch && solveMem(s, p, i + 1, j);
            ans = emptyCase || precElementCase;
        } else if (currMatch) {
            ans = solveMem(s, p, i + 1, j + 1);
        } else {
            ans = false;
        }
        
        dp[i][j] = ans;
        return ans;
    }

    public boolean isMatch(String s, String p) {
        dp = new Boolean[s.length() + 1][p.length() + 1];
        return solveMem(s, p, 0, 0);
    }
}

public class Main {
    public static void main(String[] args) {
        SolutionMemoization sol = new SolutionMemoization();
        String s = "mississippi";
        String p = "mis*is*p*.";
        System.out.println("Input String: \"" + s + "\", Pattern: \"" + p + "\"");
        System.out.println("Output: " + sol.isMatch(s, p));
    }
}
