import java.util.*;

class PrimAdjacencyMatrix {
    private int V;
    private int[][] graph;

    public PrimAdjacencyMatrix(int vertices) {
        V = vertices;
        graph = new int[V][V];
    }

    public void addEdge(int u, int v, int w) {
        graph[u][v] = w;
        graph[v][u] = w;
    }

    public List<int[]> mst() {
        int[] key = new int[V], parent = new int[V];
        boolean[] inMST = new boolean[V];
        Arrays.fill(key, Integer.MAX_VALUE);
        Arrays.fill(parent, -1);
        key[0] = 0;

        for (int count = 0; count < V - 1; count++) {
            int u = -1;
            for (int i = 0; i < V; i++)
                if (!inMST[i] && (u == -1 || key[i] < key[u]))
                    u = i;

            inMST[u] = true;

            for (int v = 0; v < V; v++) {
                if (graph[u][v] != 0 && !inMST[v] && graph[u][v] < key[v]) {
                    key[v] = graph[u][v];
                    parent[v] = u;
                }
            }
        }

        List<int[]> mstEdges = new ArrayList<>();
        for (int v = 1; v < V; v++)
            mstEdges.add(new int[]{parent[v], v, key[v]});
        return mstEdges;
    }
}
