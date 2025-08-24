class SolutionRecursion {
    private boolean solveRec(String s, String p, int i, int j) {
        if (i == s.length() && j == p.length()) {
            return true;
        }
        if (j == p.length()) {
            return false;
        }

        boolean currMatch = (i < s.length()) && (p.charAt(j) == '.' || s.charAt(i) == p.charAt(j));

        if (j + 1 < p.length() && p.charAt(j + 1) == '*') {
            boolean emptyCase = solveRec(s, p, i, j + 2);
            boolean precElementCase = currMatch && solveRec(s, p, i + 1, j);
            return emptyCase || precElementCase;
        } else if (currMatch) {
            return solveRec(s, p, i + 1, j + 1);
        } else {
            return false;
        }
    }

    public boolean isMatch(String s, String p) {
        return solveRec(s, p, 0, 0);
    }
}

public class Main {
    public static void main(String[] args) {
        SolutionRecursion sol = new SolutionRecursion();
        String s = "mississippi";
        String p = "mis*is*p*.";
        System.out.println("Input String: \"" + s + "\", Pattern: \"" + p + "\"");
        System.out.println("Output: " + sol.isMatch(s, p));
    }
}
