#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void rotate(vector<vector<int>>& matrix) {
    int N = matrix.size();

    for(int i = 0; i < N; ++i) {
        for(int j = i; j < N; ++j) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    for(int i = 0; i < N; ++i) {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

void printMatrix(const vector<vector<int>>& matrix) {
    for (auto row : matrix) {
        for (int val : row) cout << val << " ";
        cout << endl;
    }
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "Original Matrix:\n";
    printMatrix(matrix);

    rotate(matrix);

    cout << "\nRotated Matrix:\n";
    printMatrix(matrix);

    return 0;
}
