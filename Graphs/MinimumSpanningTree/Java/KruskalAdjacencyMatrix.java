import java.util.*;

class KruskalAdjacencyMatrix {
    private int V;
    private int[][] adj;
    private int[] parent, rank;

    public KruskalAdjacencyMatrix(int vertices) {
        V = vertices;
        adj = new int[V][V];
    }

    public void addEdge(int u, int v, int w) {
        adj[u][v] = w;
        adj[v][u] = w;
    }

    private int find(int u) {
        if (u != parent[u])
            parent[u] = find(parent[u]);
        return parent[u];
    }

    private void unite(int u, int v) {
        int pu = find(u), pv = find(v);
        if (pu != pv) {
            if (rank[pu] < rank[pv]) {
                int temp = pu; pu = pv; pv = temp;
            }
            parent[pv] = pu;
            if (rank[pu] == rank[pv]) rank[pu]++;
        }
    }

    public List<int[]> mst() {
        List<int[]> edges = new ArrayList<>();
        for (int i = 0; i < V; i++)
            for (int j = i + 1; j < V; j++)
                if (adj[i][j] != 0)
                    edges.add(new int[]{adj[i][j], i, j});

        edges.sort(Comparator.comparingInt(a -> a[0]));
        parent = new int[V];
        rank = new int[V];
        for (int i = 0; i < V; i++) parent[i] = i;

        List<int[]> mstEdges = new ArrayList<>();
        for (int[] e : edges) {
            if (find(e[1]) != find(e[2])) {
                unite(e[1], e[2]);
                mstEdges.add(new int[]{e[1], e[2], e[0]});
            }
        }
        return mstEdges;
    }
}
