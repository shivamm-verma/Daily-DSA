#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<vector<int>> indegree(m, vector<int>(n, 0));
        vector<vector<int>> dp(m, vector<int>(n, 1));
        
        int dx[4] = {0, 0, -1, 1};
        int dy[4] = {-1, 1, 0, 0};
        
        // Calculate indegree for each cell
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                for(int k = 0; k < 4; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    
                    if(nx >= 0 && nx < m && ny >= 0 && ny < n && 
                       matrix[nx][ny] < matrix[i][j]) {
                        indegree[i][j]++;
                    }
                }
            }
        }
        
        // Add all cells with indegree 0 to queue
        queue<pair<int, int>> q;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(indegree[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }
        
        int maxLength = 1;
        
        // Process cells in topological order
        while(!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            
            for(int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                
                if(nx >= 0 && nx < m && ny >= 0 && ny < n && 
                   matrix[nx][ny] > matrix[x][y]) {
                    dp[nx][ny] = max(dp[nx][ny], dp[x][y] + 1);
                    maxLength = max(maxLength, dp[nx][ny]);
                    indegree[nx][ny]--;
                    
                    if(indegree[nx][ny] == 0) {
                        q.push({nx, ny});
                    }
                }
            }
        }
        
        return maxLength;
    }
};
int main(){
    vector<vector<int>> matrix = {
        {9, 9, 4},
        {6, 6, 8},
        {2, 1, 1}
    };
    Solution sol;
    int result = sol.longestIncreasingPath(matrix);
    cout << "Longest Increasing Path: " << result << endl;

    return 0;
}