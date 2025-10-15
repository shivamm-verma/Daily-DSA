import java.util.*;

public class Main {
    static int dfs(int node, List<List<Integer>> adj, int[] gold, boolean[] visited) {
        visited[node] = true;
        int total = gold[node];
        for (int nei : adj.get(node)) {
            if (!visited[nei])
                total += dfs(nei, adj, gold, visited);
        }
        return total;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int[] gold = new int[n];
        for (int i = 0; i < n; i++) gold[i] = sc.nextInt();

        int e = sc.nextInt();
        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < n; i++) adj.add(new ArrayList<>());

        for (int i = 0; i < e; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            adj.get(u).add(v);
            adj.get(v).add(u);
        }

        boolean[] visited = new boolean[n];
        int maxGold = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i])
                maxGold = Math.max(maxGold, dfs(i, adj, gold, visited));
        }

        System.out.println(maxGold);
    }
}
