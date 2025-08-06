#include <iostream>
#include <vector>
using namespace std;

// Function to return transpose of the matrix
vector<vector<int>> transpose(vector<vector<int>>& mat) {
    int rows = mat.size();
    int cols = mat[0].size();

    // Create a new matrix with dimensions cols x rows
    vector<vector<int>> tMat(cols, vector<int>(rows));

    // Fill the transposed matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            tMat[j][i] = mat[i][j];
        }
    }

    return tMat;
}

int main() {
    vector<vector<int>> mat = {
        {1, 1, 1, 1},
        {2, 2, 2, 2},
        {3, 3, 3, 3},
        {4, 4, 4, 4}
    };

    vector<vector<int>> result = transpose(mat);

    // Print the result
    for (auto& row : result) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}

/*
Time Complexity: O(n * m)
- We traverse each element of the original matrix once.

Space Complexity: O(n * m)
- A new matrix of size m x n is created to store the transpose.
*/