import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class Solution {
    public int secureCity(char[][] grid) {
        if (grid == null || grid.length == 0 || grid[0].length == 0) {
            return 0;
        }
        int m = grid.length;
        int n = grid[0].length;
        boolean[][] protectedGrid = new boolean[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 'B') {
                    for (int k = i + 1; k < m && grid[k][j] != 'O'; k++) protectedGrid[k][j] = true;
                    for (int k = i - 1; k >= 0 && grid[k][j] != 'O'; k--) protectedGrid[k][j] = true;
                    for (int k = j + 1; k < n && grid[i][k] != 'O'; k++) protectedGrid[i][k] = true;
                    for (int k = j - 1; k >= 0 && grid[i][k] != 'O'; k--) protectedGrid[i][k] = true;
                }
            }
        }
        boolean[][] visited = new boolean[m][n];
        int regions = 0;
        int[] dx = {0, 0, 1, -1};
        int[] dy = {1, -1, 0, 0};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 'E' && !protectedGrid[i][j] && !visited[i][j]) {
                    regions++;
                    Queue<int[]> q = new LinkedList<>();
                    q.offer(new int[]{i, j});
                    visited[i][j] = true;
                    while (!q.isEmpty()) {
                        int[] curr = q.poll();
                        int r = curr[0];
                        int c = curr[1];
                        for (int k = 0; k < 4; k++) {
                            int nr = r + dx[k];
                            int nc = c + dy[k];
                            if (nr >= 0 && nr < m && nc >= 0 && nc < n &&
                                grid[nr][nc] == 'E' && !protectedGrid[nr][nc] && !visited[nr][nc]) {
                                visited[nr][nc] = true;
                                q.offer(new int[]{nr, nc});
                            }
                        }
                    }
                }
            }
        }
        return regions;
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int m = sc.nextInt();
        int n = sc.nextInt();
        char[][] grid = new char[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                grid[i][j] = sc.next().charAt(0);
            }
        }
        Solution sol = new Solution();
        System.out.println(sol.secureCity(grid));
        sc.close();
    }
}