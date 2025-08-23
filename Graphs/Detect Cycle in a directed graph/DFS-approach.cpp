#include <bits/stdc++.h>
class Solution {
private:
    bool dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& recStack) {
        visited[node] = true;
        recStack[node] = true;

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                if (dfs(neighbor, adj, visited, recStack)) return true;
            } else if (recStack[neighbor]) {
                return true; // cycle found
            }
        }

        recStack[node] = false;
        return false;
    }

public:
    bool hasCycle(int n, vector<vector<int>>& adj) {
        vector<bool> visited(n, false), recStack(n, false);

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                if (dfs(i, adj, visited, recStack)) return true;
            }
        }
        return false;
    }
};
