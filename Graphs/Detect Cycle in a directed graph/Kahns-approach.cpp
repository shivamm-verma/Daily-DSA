#include <bits/stdc++.h>
class Solution {
public:
    bool hasCycle(int n, vector<vector<int>>& adj) {
        vector<int> indegree(n, 0);

        for (int u = 0; u < n; u++) {
            for (int v : adj[u]) {
                indegree[v]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        int count = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            count++;

            for (int neighbor : adj[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        return count != n; 
    }
};
