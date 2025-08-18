#include <vector>
#include <queue>
#include <tuple>
#include <climits>
using namespace std;

class PrimAdjacencyList {
    int V;
    vector<vector<pair<int,int>>> adj;

public:
    PrimAdjacencyList(int vertices) : V(vertices) {
        adj.resize(V);
    }

    void addEdge(int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<tuple<int,int,int>> mst() {
        vector<int> key(V, INT_MAX), parent(V, -1);
        vector<bool> inMST(V, false);
        key[0] = 0;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        pq.push({0, 0});

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();
            if (inMST[u]) continue;
            inMST[u] = true;

            for (auto &[v, w] : adj[u]) {
                if (!inMST[v] && w < key[v]) {
                    key[v] = w;
                    parent[v] = u;
                    pq.push({key[v], v});
                }
            }
        }

        vector<tuple<int,int,int>> mstEdges;
        for (int v = 1; v < V; v++)
            mstEdges.push_back({parent[v], v, key[v]});
        return mstEdges;
    }
};
