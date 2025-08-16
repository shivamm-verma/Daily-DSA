#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dfs(vector<vector<int>>& matrix, int x, int y) {
        int m = matrix.size();
        int n = matrix[0].size();
        int maxPath = 1;
        
        int dx[4] = {0, 0, -1, 1};
        int dy[4] = {-1, 1, 0, 0};
        
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx >= 0 && nx < m && ny >= 0 && ny < n && matrix[nx][ny] > matrix[x][y]) {
                maxPath = max(maxPath, 1 + dfs(matrix, nx, ny));
            }
        }
        
        return maxPath;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int result = 1;
        
        // Try starting from every cell
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                result = max(result, dfs(matrix, i, j));
            }
        }
        
        return result;
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