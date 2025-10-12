#include <bits/stdc++.h>
using namespace std;

int dfs(int node, vector<vector<int>>& adj, vector<int>& gold, vector<bool>& visited) {
    visited[node] = true;
    int total = gold[node];
    for (int nei : adj[node]) {
        if (!visited[nei])
            total += dfs(nei, adj, gold, visited);
    }
    return total;
}

int main() {
    int n;
    cin >> n;
    vector<int> gold(n);
    for (int i = 0; i < n; i++) cin >> gold[i];

    int e;
    cin >> e;
    vector<vector<int>> adj(n);
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(n, false);
    int maxGold = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i])
            maxGold = max(maxGold, dfs(i, adj, gold, visited));
    }

    cout << maxGold << endl;
    return 0;
}
