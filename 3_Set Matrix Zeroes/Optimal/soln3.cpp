// C++ Code

#include <iostream>
using namespace std;

void setMatrixZero(int matrix[][100], int rows, int cols) {
    bool firstRow = false, firstCol = false;

    // Check if first column has any zero
    for (int i = 0; i < rows; i++) {
        if (matrix[i][0] == 0)
            firstCol = true;
    }

    // Check if first row has any zero
    for (int j = 0; j < cols; j++) {
        if (matrix[0][j] == 0)
            firstRow = true;
    }

    // Use first row and column as markers
    for (int i = 1; i < rows; i++) {
        for (int j = 1; j < cols; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    // Set zeroes based on markers
    for (int i = 1; i < rows; i++) {
        for (int j = 1; j < cols; j++) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;
        }
    }

    // Update first row if needed
    if (firstRow) {
        for (int j = 0; j < cols; j++)
            matrix[0][j] = 0;
    }

    // Update first column if needed
    if (firstCol) {
        for (int i = 0; i < rows; i++)
            matrix[i][0] = 0;
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
