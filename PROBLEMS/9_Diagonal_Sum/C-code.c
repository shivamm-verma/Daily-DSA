#include <stdio.h>
int diagonalSum(int matrix[][100],int n){
    int sum = 0;
    if (n<=0){
        return 0;
    }
    for(int i=0;i<n;i++){
        sum+=matrix[i][i];
        if(i!=n-1-i){
            sum+=matrix[i][n-1-i];
        }
    }
    return sum;
}
int main() {
    int n;
    printf("Enter the size of the square matrix (n): ");
    scanf("%d", &n);
    if (n<=0) {
        printf("Invalid matrix size. Please enter a positive integer.\n");
        return 1;
    }
    int matrix[100][100];
    printf("Enter the elements of the matrix:\n");
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            printf("Enter element at position [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
    int totalSum=diagonalSum(matrix, n);
    printf("The sum of the main and anti-diagonals is: %d\n", totalSum);
    return 0;
}