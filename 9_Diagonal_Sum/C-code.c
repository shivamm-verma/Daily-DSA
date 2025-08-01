//Time Complexity O(n)

#include <stdio.h>
// Function to calculate the sum of the main and anti-diagonals of a square matrix
int diagonalSum(int matrix[][100], int n) {
    int sum = 0;
    // Check if the matrix is valid (non-negative size)
    if (n <= 0) {
        return 0;
    }
    // Iterate through the matrix once to calculate the sum
    for (int i = 0; i < n; i++) {
        // Add the main diagonal element
        sum += matrix[i][i];
        // Add the anti-diagonal element
        // The condition `i != n - 1 - i` prevents adding the center element twice for odd-sized matrices
        if (i != n - 1 - i) {
            sum += matrix[i][n - 1 - i];
        }
    }
    return sum;
}
int main() {
    int n;
    // Get the size of the square matrix from the user
    printf("Enter the size of the square matrix (n): ");
    scanf("%d", &n);
    // Validate the size
    if (n <= 0) {
        printf("Invalid matrix size. Please enter a positive integer.\n");
        return 1;
    }
    int matrix[100][100]; // Assuming a maximum size of 100x100
    // Get matrix elements from the user
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Enter element at position [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
    // Calculate and print the diagonal sum
    int totalSum = diagonalSum(matrix, n);
    printf("The sum of the main and anti-diagonals is: %d\n", totalSum);
    return 0;
}