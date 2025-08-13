#include <vector>
#include <climits>
using namespace std;

class PrimAdjacencyMatrix {
    int V;
    vector<vector<int>> graph;

public:
    PrimAdjacencyMatrix(int vertices) : V(vertices) {
        graph.assign(V, vector<int>(V, 0));
    }

    void addEdge(int u, int v, int w) {
        graph[u][v] = w;
        graph[v][u] = w;
    }

    vector<tuple<int,int,int>> mst() {
        vector<int> key(V, INT_MAX), parent(V, -1);
        vector<bool> inMST(V, false);
        key[0] = 0;

        for (int count = 0; count < V - 1; count++) {
            int u = -1;
            for (int i = 0; i < V; i++)
                if (!inMST[i] && (u == -1 || key[i] < key[u]))
                    u = i;

            inMST[u] = true;

            for (int v = 0; v < V; v++) {
                if (graph[u][v] && !inMST[v] && graph[u][v] < key[v]) {
                    key[v] = graph[u][v];
                    parent[v] = u;
                }
            }
        }

        vector<tuple<int,int,int>> mstEdges;
        for (int v = 1; v < V; v++)
            mstEdges.push_back({parent[v], v, key[v]});
        return mstEdges;
    }
};
