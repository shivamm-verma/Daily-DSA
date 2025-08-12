#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int secureCity(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> protectedGrid(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 'B') {
                    for (int k = i + 1; k < m && grid[k][j] != 'O'; ++k) protectedGrid[k][j] = true;
                    for (int k = i - 1; k >= 0 && grid[k][j] != 'O'; --k) protectedGrid[k][j] = true;
                    for (int k = j + 1; k < n && grid[i][k] != 'O'; ++k) protectedGrid[i][k] = true;
                    for (int k = j - 1; k >= 0 && grid[i][k] != 'O'; --k) protectedGrid[i][k] = true;
                }
            }
        }
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int regions = 0;
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 'E' && !protectedGrid[i][j] && !visited[i][j]) {
                    regions++;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    visited[i][j] = true;
                    while (!q.empty()) {
                        pair<int, int> curr = q.front();
                        q.pop();
                        for (int k = 0; k < 4; ++k) {
                            int ni = curr.first + dx[k];
                            int nj = curr.second + dy[k];
                            if (ni >= 0 && ni < m && nj >= 0 && nj < n &&
                                grid[ni][nj] == 'E' && !protectedGrid[ni][nj] && !visited[ni][nj]) {
                                visited[ni][nj] = true;
                                q.push({ni, nj});
                            }
                        }
                    }
                }
            }
        }
        return regions;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m, n;
    cin >> m >> n;
    vector<vector<char>> grid(m, vector<char>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }
    Solution sol;
    cout << sol.secureCity(grid) << endl;
    return 0;
}