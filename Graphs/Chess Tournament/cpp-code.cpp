#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int>& gold, vector<vector<int>>& adj, vector<bool>& visited, int& sum) {
    visited[node] = true;
    sum += gold[node];
    for (int nei : adj[node]) {
        if (!visited[nei]) dfs(nei, gold, adj, visited, sum);
    }
}

int maxGold(int N, vector<int>& gold, vector<vector<int>>& tunnels) {
    vector<vector<int>> adj(N);
    for (auto& t : tunnels) {
        adj[t[0]].push_back(t[1]);
        adj[t[1]].push_back(t[0]);
    }

    vector<bool> visited(N, false);
    int max_gold = 0;

    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            int sum = 0;
            dfs(i, gold, adj, visited, sum);
            max_gold = max(max_gold, sum);
        }
    }
    return max_gold;
}

int main() {
    int N = 5;
    vector<int> gold = {2, 5, 7, 1, 3};
    vector<vector<int>> tunnels = {{0,1}, {1,2}, {2,3}, {3,4}};
    cout << maxGold(N, gold, tunnels) << endl; // Output: 18
}
