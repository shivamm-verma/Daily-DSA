import java.util.*;

class PrimAdjacencyList {
    private int V;
    private List<List<int[]>> adj;

    public PrimAdjacencyList(int vertices) {
        V = vertices;
        adj = new ArrayList<>();
        for (int i = 0; i < V; i++)
            adj.add(new ArrayList<>());
    }

    public void addEdge(int u, int v, int w) {
        adj.get(u).add(new int[]{v, w});
        adj.get(v).add(new int[]{u, w});
    }

    public List<int[]> mst() {
        int[] key = new int[V], parent = new int[V];
        boolean[] inMST = new boolean[V];
        Arrays.fill(key, Integer.MAX_VALUE);
        Arrays.fill(parent, -1);
        key[0] = 0;

        PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));
        pq.add(new int[]{0, 0});

        while (!pq.isEmpty()) {
            int u = pq.poll()[1];
            if (inMST[u]) continue;
            inMST[u] = true;

            for (int[] p : adj.get(u)) {
                int v = p[0], w = p[1];
                if (!inMST[v] && w < key[v]) {
                    key[v] = w;
                    parent[v] = u;
                    pq.add(new int[]{key[v], v});
                }
            }
        }

        List<int[]> mstEdges = new ArrayList<>();
        for (int v = 1; v < V; v++)
            mstEdges.add(new int[]{parent[v], v, key[v]});
        return mstEdges;
    }
}
