// Java Code

import java.util.Scanner;

public class soln{

    public static void setMatrixZero(int[][] matrix, int rows, int cols) {
        int marker = -999999;

        // First pass: mark rows and columns
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == 0) {
                    // Mark row
                    for (int k = 0; k < cols; k++) {
                        if (matrix[i][k] != 0)
                            matrix[i][k] = marker;
                    }
                    // Mark column
                    for (int k = 0; k < rows; k++) {
                        if (matrix[k][j] != 0)
                            matrix[k][j] = marker;
                    }
                }
            }
        }

        // Second pass: replace marker with 0
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == marker) {
                    matrix[i][j] = 0;
                }
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of rows: ");
        int rows = sc.nextInt();

        System.out.print("Enter number of columns: ");
        int cols = sc.nextInt();

        int[][] matrix = new int[rows][cols];
        System.out.println("Enter matrix elements:");

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                matrix[i][j] = sc.nextInt();
            }
        }

        setMatrixZero(matrix, rows, cols);

        System.out.println("\nMatrix after setting zeroes:");
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                System.out.print(matrix[i][j] + " ");
            }
            System.out.println();
        }

        sc.close();
    }
}
