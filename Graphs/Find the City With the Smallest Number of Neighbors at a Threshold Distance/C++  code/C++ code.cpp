#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
    
    for (auto& edge : edges) {
        int u = edge[0], v = edge[1], wt = edge[2];
        dist[u][v] = wt;
        dist[v][u] = wt;
    }

    for (int i = 0; i < n; ++i)
        dist[i][i] = 0;

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][k] == INT_MAX || dist[k][j] == INT_MAX) continue;
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    int cityCnt = n + 1;
    int cityNo = -1;

    for (int i = 0; i < n; ++i) {
        int cnt = 0;
        for (int j = 0; j < n; ++j) {
            if (dist[i][j] <= distanceThreshold) {
                cnt++;
            }
        }
        if (cnt <= cityCnt) {
            cityCnt = cnt;
            cityNo = i;
        }
    }

    return cityNo;
}

int main() {
    int n = 4;
    vector<vector<int>> edges = {{0, 1, 3}, {1, 2, 1}, {1, 3, 4}, {2, 3, 1}};
    int distanceThreshold = 4;
    cout << findTheCity(n, edges, distanceThreshold) << endl;
    return 0;
}
