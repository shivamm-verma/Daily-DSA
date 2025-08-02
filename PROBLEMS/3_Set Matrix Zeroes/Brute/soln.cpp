// C++ Code

#include <iostream>
using namespace std;

void setMatrixZero(int matrix[][100], int rows, int cols) {
    int marker = -999999;

    // First pass: mark rows and columns with the marker
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 0) {
                // Mark the entire row
                for (int k = 0; k < cols; k++) {
                    if (matrix[i][k] != 0)
                        matrix[i][k] = marker;
                }
                // Mark the entire column
                for (int k = 0; k < rows; k++) {
                    if (matrix[k][j] != 0)
                        matrix[k][j] = marker;
                }
            }
        }
    }

    // Second pass: convert marker to 0
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == marker)
                matrix[i][j] = 0;
        }
    }
}

int main() {
    int matrix[100][100];
    int rows, cols;

    cout << "Enter rows and columns: ";
    cin >> rows >> cols;

    cout << "Enter matrix elements:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    setMatrixZero(matrix, rows, cols);

    cout << "\nMatrix after setting zeroes:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
