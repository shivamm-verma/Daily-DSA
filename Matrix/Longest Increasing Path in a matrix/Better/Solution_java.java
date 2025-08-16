import java.util.*;

class Solution {
    private int[][] dp;
    private int[][] matrix;
    private int m, n;
    private int[] dx = {0, 0, -1, 1};
    private int[] dy = {-1, 1, 0, 0};

    public int dfs(int x, int y) {
        if (dp[x][y] != 0) {
            return dp[x][y];
        }

        int maxx = 1; // minimum length is 1 (the cell itself)

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < m && ny >= 0 && ny < n && matrix[nx][ny] > matrix[x][y]) {
                maxx = Math.max(maxx, 1 + dfs(nx, ny));
            }
        }

        dp[x][y] = maxx;
        return maxx;
    }

    public int longestIncreasingPath(int[][] matrix) {
        this.matrix = matrix;
        this.m = matrix.length;
        this.n = matrix[0].length;
        this.dp = new int[m][n];

        int count = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                count = Math.max(count, dfs(i, j));
            }
        }

        return count;
    }

    public static void main(String[] args) {
        int[][] matrix = {
            {9, 9, 4},
            {6, 6, 8},
            {2, 1, 1}
        };

        Solution sol = new Solution();
        int result = sol.longestIncreasingPath(matrix);
        System.out.println("Longest Increasing Path: " + result);
    }
}
