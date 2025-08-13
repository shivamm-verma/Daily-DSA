#include <vector>
#include <algorithm>
using namespace std;

class KruskalAdjacencyList {
    int V;
    vector<vector<pair<int,int>>> adj;
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
    KruskalAdjacencyList(int vertices) : V(vertices) {
        adj.resize(V);
    }

    void addEdge(int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<tuple<int,int,int>> mst() {
        vector<tuple<int,int,int>> edges;
        for (int u = 0; u < V; u++) {
            for (auto &p : adj[u]) {
                int v = p.first, w = p.second;
                if (u < v) edges.push_back({w, u, v});
            }
        }

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
