//Time Complexity O(n)

import java.util.Scanner;
public class Java_code {
    public static int diagonalSum(int[][] matrix, int n) {
        int sum = 0;
        // Handle empty or invalid matrix size
        if (n <= 0) {
            return 0;
        }
        // Iterate through the matrix once to calculate the sum
        for (int i = 0; i < n; i++) {
            // Add the main diagonal element
            sum += matrix[i][i];
            if (i != n - 1 - i) {
                sum += matrix[i][n - 1 - i];
            }
        }
        return sum;
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        // Get the size of the square matrix from the user
        System.out.print("Enter the size of the square matrix (n): ");
        int n = scanner.nextInt();
        // Validate the size
        if (n <= 0) {
            System.out.println("Invalid matrix size. Please enter a positive integer.");
            return;
        }
        int[][] matrix = new int[n][n];
        // Get matrix elements from the user
        System.out.println("Enter the elements of the matrix:");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                System.out.printf("Enter element at position [%d][%d]: ", i, j);
                matrix[i][j] = scanner.nextInt();
            }
        }
        // Calculate and print the diagonal sum
        int totalSum = diagonalSum(matrix, n);
        System.out.println("The sum of the main and anti-diagonals is: " + totalSum);
        scanner.close();
    }
}