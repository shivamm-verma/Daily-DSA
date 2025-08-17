import java.util.*;

public class WeightedDamerauLevenshteinDistance {

    static class DLResult {
        int cost;
        List<String> operations;
        DLResult() { this.cost = 0; this.operations = new ArrayList<>(); }
        DLResult(int cost, List<String> operations) {
            this.cost = cost;
            this.operations = new ArrayList<>(operations);
        }
    }

    static class OperationCosts {
        int insertCost, deleteCost, replaceCost, transposeCost;
        OperationCosts() { this(1, 1, 1, 1); }
        OperationCosts(int ins, int del, int rep, int trans) {
            this.insertCost = ins; this.deleteCost = del;
            this.replaceCost = rep; this.transposeCost = trans;
        }
    }

    private static int minimumCost(int a, int b, int c) {
        return Math.min(a, Math.min(b, c));
    }
    private static int minimumCost(int a, int b, int c, int d) {
        return Math.min(Math.min(a, b), Math.min(c, d));
    }

    public static int damerauLevenshteinWeightedCostOnly(String str1, String str2, OperationCosts costs) {
        int m = str1.length(), n = str2.length();
        int[][] dp = new int[m + 1][n + 1];
        for (int i = 0; i <= m; i++) dp[i][0] = i * costs.deleteCost;
        for (int j = 0; j <= n; j++) dp[0][j] = j * costs.insertCost;

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (str1.charAt(i - 1) == str2.charAt(j - 1)) dp[i][j] = dp[i - 1][j - 1];
                else {
                    int ins = dp[i][j - 1] + costs.insertCost;
                    int del = dp[i - 1][j] + costs.deleteCost;
                    int rep = dp[i - 1][j - 1] + costs.replaceCost;
                    if (i > 1 && j > 1 && str1.charAt(i - 1) == str2.charAt(j - 2) && str1.charAt(i - 2) == str2.charAt(j - 1)) {
                        int trans = dp[i - 2][j - 2] + costs.transposeCost;
                        dp[i][j] = minimumCost(ins, del, rep, trans);
                    } else dp[i][j] = minimumCost(ins, del, rep);
                }
            }
        }
        return dp[m][n];
    }

    public static DLResult damerauLevenshteinWeightedCostAndOperation(String str1, String str2, OperationCosts costs) {
        int m = str1.length(), n = str2.length();
        DLResult[][] dp = new DLResult[m + 1][n + 1];
        for (int i = 0; i <= m; i++) for (int j = 0; j <= n; j++) dp[i][j] = new DLResult();

        for (int i = 0; i <= m; i++) {
            dp[i][0].cost = i * costs.deleteCost;
            for (int k = 0; k < i; k++) dp[i][0].operations.add("DELETE '" + str1.charAt(k) + "'");
        }
        for (int j = 0; j <= n; j++) {
            dp[0][j].cost = j * costs.insertCost;
            for (int k = 0; k < j; k++) dp[0][j].operations.add("INSERT '" + str2.charAt(k) + "'");
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (str1.charAt(i - 1) == str2.charAt(j - 1)) {
                    dp[i][j].cost = dp[i - 1][j - 1].cost;
                    dp[i][j].operations = new ArrayList<>(dp[i - 1][j - 1].operations);
                    dp[i][j].operations.add("MATCH '" + str1.charAt(i - 1) + "'");
                } else {
                    int ins = dp[i][j - 1].cost + costs.insertCost;
                    int del = dp[i - 1][j].cost + costs.deleteCost;
                    int rep = dp[i - 1][j - 1].cost + costs.replaceCost;
                    boolean canTranspose = (i > 1 && j > 1 &&
                            str1.charAt(i - 1) == str2.charAt(j - 2) &&
                            str1.charAt(i - 2) == str2.charAt(j - 1));
                    if (canTranspose) {
                        int trans = dp[i - 2][j - 2].cost + costs.transposeCost;
                        int minVal = minimumCost(ins, del, rep, trans);
                        dp[i][j].cost = minVal;
                        if (minVal == trans) {
                            dp[i][j].operations = new ArrayList<>(dp[i - 2][j - 2].operations);
                            dp[i][j].operations.add("TRANSPOSE");
                        } else if (minVal == rep) {
                            dp[i][j].operations = new ArrayList<>(dp[i - 1][j - 1].operations);
                            dp[i][j].operations.add("REPLACE");
                        } else if (minVal == del) {
                            dp[i][j].operations = new ArrayList<>(dp[i - 1][j].operations);
                            dp[i][j].operations.add("DELETE");
                        } else {
                            dp[i][j].operations = new ArrayList<>(dp[i][j - 1].operations);
                            dp[i][j].operations.add("INSERT");
                        }
                    } else {
                        int minVal = minimumCost(ins, del, rep);
                        dp[i][j].cost = minVal;
                        if (minVal == rep) {
                            dp[i][j].operations = new ArrayList<>(dp[i - 1][j - 1].operations);
                            dp[i][j].operations.add("REPLACE");
                        } else if (minVal == del) {
                            dp[i][j].operations = new ArrayList<>(dp[i - 1][j].operations);
                            dp[i][j].operations.add("DELETE");
                        } else {
                            dp[i][j].operations = new ArrayList<>(dp[i][j - 1].operations);
                            dp[i][j].operations.add("INSERT");
                        }
                    }
                }
            }
        }
        return dp[m][n];
    }

    public static void main(String[] args) {
        String s1 = "kitten", s2 = "sitting";
        OperationCosts costs = new OperationCosts();
        System.out.println("Distance: " + damerauLevenshteinWeightedCostOnly(s1, s2, costs));
        DLResult res = damerauLevenshteinWeightedCostAndOperation(s1, s2, costs);
        System.out.println("Detailed distance: " + res.cost);
        for (String op : res.operations) System.out.println(op);
    }
}
