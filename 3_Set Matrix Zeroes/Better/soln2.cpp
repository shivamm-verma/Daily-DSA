// C++ Code

#include <iostream>
using namespace std;

void setMatrixZero(int matrix[][100], int rows, int cols) {
    int row[100] = {0};
    int col[100] = {0};

    // Mark rows and columns that contain 0
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 0) {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    // Set zeroes based on row[] and col[]
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (row[i] == 1 || col[j] == 1) {
                matrix[i][j] = 0;
            }
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
