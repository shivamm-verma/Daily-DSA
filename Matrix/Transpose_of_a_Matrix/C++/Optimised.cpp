#include <iostream>
#include <vector>
using namespace std;

// Function to transpose a square matrix in-place
vector<vector<int>> transpose(vector<vector<int>>& mat) {
    int n = mat.size();  // Square matrix: n x n

    // Traverse the upper triangle of the matrix
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // Swap elements across the diagonal
            swap(mat[i][j], mat[j][i]);
        }
    }

    return mat;
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
Time Complexity: O(n^2)
- Only the upper triangle of the matrix is traversed and swapped.

Space Complexity: O(1)
- Transposition is done in-place, without any extra matrix.
- This approach works only for square matrices.
*/
