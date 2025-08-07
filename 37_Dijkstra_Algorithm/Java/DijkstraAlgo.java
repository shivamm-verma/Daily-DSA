import java.util.*;

public class DijkstraAlgo {
    static class Pair {
        int v, w;
        Pair(int v, int w) {
            this.v = v;
            this.w = w;
        }
    }

    public static int[] dijkstra(int V, List<List<Pair>> adj, int src) {
        PriorityQueue<Pair> pq = new PriorityQueue<>(Comparator.comparingInt(a -> a.w));
        int[] dist = new int[V];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[src] = 0;
        pq.offer(new Pair(src, 0));

        while (!pq.isEmpty()) {
            Pair cur = pq.poll();
            for (Pair neighbor : adj.get(cur.v)) {
                if (dist[neighbor.v] > cur.w + neighbor.w) {
                    dist[neighbor.v] = cur.w + neighbor.w;
                    pq.offer(new Pair(neighbor.v, dist[neighbor.v]));
                }
            }
        }

        return dist;
    }
}

// TC: O((V + E) * log V)
// SC: O(V)
