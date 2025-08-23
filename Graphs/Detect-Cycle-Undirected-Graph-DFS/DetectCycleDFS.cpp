#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, int parent, vector<bool> &visited, vector<vector<int>> &graph) {
    visited[node] = true;

    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            if (dfs(neighbor, node, visited, graph))
                return true;
        } else if (neighbor != parent) {
            return true; // Found cycle
        }
    }
    return false;
}

bool hasCycle(int V, vector<vector<int>> &graph) {
    vector<bool> visited(V, false);
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, visited, graph))
                return true;
        }
    }
    return false;
}

int main() {
    int V = 4;
    vector<vector<int>> graph(V);

    // Example graph: 0-1, 1-2, 2-0
    graph[0].push_back(1);
    graph[1].push_back(0);

    graph[1].push_back(2);
    graph[2].push_back(1);

    graph[2].push_back(0);
    graph[0].push_back(2);

    cout << (hasCycle(V, graph) ? "Cycle exists" : "No cycle") << endl;
    return 0;
}