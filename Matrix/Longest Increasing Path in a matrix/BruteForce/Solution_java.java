import java.util.*;

class Solution {
    public int dfs(int[][] matrix, int x, int y) {
        int m = matrix.length;
        int n = matrix[0].length;
        int maxPath = 1;

        int[] dx = {0, 0, -1, 1};
        int[] dy = {-1, 1, 0, 0};

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < m && ny >= 0 && ny < n && matrix[nx][ny] > matrix[x][y]) {
                maxPath = Math.max(maxPath, 1 + dfs(matrix, nx, ny));
            }
        }

        return maxPath;
    }

    public int longestIncreasingPath(int[][] matrix) {
        int m = matrix.length;
        int n = matrix[0].length;
        int result = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                result = Math.max(result, dfs(matrix, i, j));
            }
        }

        return result;
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
