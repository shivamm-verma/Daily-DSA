import java.util.*;

public class KingdomGoldVault {
    static void dfs(int node, boolean[] visited, List<List<Integer>> adj, int[] gold, int[] sum) {
        visited[node] = true;
        sum[0] += gold[node];
        for (int nei : adj.get(node)) {
            if (!visited[nei]) dfs(nei, visited, adj, gold, sum);
        }
    }

    public static int maxGold(int N, int[] gold, int[][] tunnels) {
        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < N; i++) adj.add(new ArrayList<>());

        for (int[] t : tunnels) {
            adj.get(t[0]).add(t[1]);
            adj.get(t[1]).add(t[0]);
        }

        boolean[] visited = new boolean[N];
        int maxGold = 0;

        for (int i = 0; i < N; i++) {
            if (!visited[i]) {
                int[] sum = {0};
                dfs(i, visited, adj, gold, sum);
                maxGold = Math.max(maxGold, sum[0]);
            }
        }
        return maxGold;
    }

    public static void main(String[] args) {
        int N = 5;
        int[] gold = {2, 5, 7, 1, 3};
        int[][] tunnels = {{0, 1}, {1, 2}, {2, 3}, {3, 4}};
        System.out.println(maxGold(N, gold, tunnels)); // Output: 18
    }
}