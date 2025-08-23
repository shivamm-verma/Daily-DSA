#include <vector>
#include <algorithm>
using namespace std;

class KruskalAdjacencyMatrix {
    int V;
    vector<vector<int>> adj;
    vector<int> parent, rank;

    int find(int u) {
        if (u != parent[u])
            parent[u] = find(parent[u]);
        return parent[u];
    }

    void unite(int u, int v) {
        int pu = find(u), pv = find(v);
        if (pu != pv) {
            if (rank[pu] < rank[pv]) swap(pu, pv);
            parent[pv] = pu;
            if (rank[pu] == rank[pv]) rank[pu]++;
        }
    }

public:
    KruskalAdjacencyMatrix(int vertices) : V(vertices) {
        adj.assign(V, vector<int>(V, 0));
    }

    void addEdge(int u, int v, int w) {
        adj[u][v] = w;
        adj[v][u] = w;
    }

    vector<tuple<int,int,int>> mst() {
        vector<tuple<int,int,int>> edges;
        for (int i = 0; i < V; i++)
            for (int j = i + 1; j < V; j++)
                if (adj[i][j] != 0)
                    edges.push_back({adj[i][j], i, j});

        sort(edges.begin(), edges.end());
        parent.resize(V);
        rank.assign(V, 0);
        for (int i = 0; i < V; i++) parent[i] = i;

        vector<tuple<int,int,int>> mstEdges;
        for (auto &[w, u, v] : edges) {
            if (find(u) != find(v)) {
                unite(u, v);
                mstEdges.push_back({u, v, w});
            }
        }
        return mstEdges;
    }
};
