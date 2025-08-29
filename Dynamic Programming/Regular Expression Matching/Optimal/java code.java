class SolutionTabulation {
    public boolean solveTab(String s, String p, int m, int n) {
        boolean[][] dp = new boolean[m + 1][n + 1];
        dp[m][n] = true;

        for (int i = m; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                boolean currMatch = (i < m) && (p.charAt(j) == '.' || s.charAt(i) == p.charAt(j));
                if (j + 1 < n && p.charAt(j + 1) == '*') {
                    dp[i][j] = dp[i][j + 2] || (currMatch && dp[i + 1][j]);
                } else if (currMatch) {
                    dp[i][j] = dp[i + 1][j + 1];
                } else {
                    dp[i][j] = false;
                }
            }
        }
        return dp[0][0];
    }

    public boolean isMatch(String s, String p) {
        return solveTab(s, p, s.length(), p.length());
    }
}

public class Main {
    public static void main(String[] args) {
        SolutionTabulation sol = new SolutionTabulation();
        String s = "mississippi";
        String p = "mis*is*p*.";
        System.out.println("Input String: \"" + s + "\", Pattern: \"" + p + "\"");
        System.out.println("Output: " + sol.isMatch(s, p));
    }
}
