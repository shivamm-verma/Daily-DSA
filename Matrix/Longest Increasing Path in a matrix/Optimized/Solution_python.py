import java.util.*;

class Solution {
    public int longestIncreasingPath(int[][] matrix) {
        int m = matrix.length, n = matrix[0].length;
        int[][] indegree = new int[m][n];
        int[][] dp = new int[m][n];

        int[] dx = {0, 0, -1, 1};
        int[] dy = {-1, 1, 0, 0};

        // Calculate indegree for each cell
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = 1; // each cell has path length at least 1
                for (int k = 0; k < 4; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n &&
                        matrix[nx][ny] < matrix[i][j]) {
                        indegree[i][j]++;
                    }
                }
            }
        }

        Queue<int[]> q = new LinkedList<>();
        // Add all cells with indegree 0
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (indegree[i][j] == 0) {
                    q.offer(new int[]{i, j});
                }
            }
        }

        int maxLength = 1;

        // Process in topological order
        while (!q.isEmpty()) {
            int[] cell = q.poll();
            int x = cell[0], y = cell[1];

            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n &&
                    matrix[nx][ny] > matrix[x][y]) {
                    dp[nx][ny] = Math.max(dp[nx][ny], dp[x][y] + 1);
                    maxLength = Math.max(maxLength, dp[nx][ny]);
                    indegree[nx][ny]--;
                    if (indegree[nx][ny] == 0) {
                        q.offer(new int[]{nx, ny});
                    }
                }
            }
        }

        return maxLength;
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
