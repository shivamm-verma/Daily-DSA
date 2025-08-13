package Recursion and Backtracking.BurstBalloon;

public class java_code {
    public int maxCoins(int[] nums) {
        int n = nums.length;
        int[] arr = new int[n + 2];
        arr[0] = 1; arr[n + 1] = 1;
        for (int i = 1; i <= n; i++) arr[i] = nums[i - 1];
        int m = n + 2;
        int[][] dp = new int[m][m];

        for (int length = 2; length < m; length++) {
            for (int l = 0; l + length < m; l++) {
                int r = l + length;
                for (int i = l + 1; i < r; i++) {
                    int val = arr[l] * arr[i] * arr[r] + dp[l][i] + dp[i][r];
                    if (val > dp[l][r]) dp[l][r] = val;
                }
            }
        }
        return dp[0][m - 1];
    }

    public static void main(String[] args) {
        java_code s = new java_code();
        System.out.println(s.maxCoins(new int[]{3,1,5,8})); // 167
    }
}
