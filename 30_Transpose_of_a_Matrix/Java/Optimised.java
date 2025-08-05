import java.util.Arrays;

public class Optimised {

    public static int[][] transpose(int[][] mat) {
        int n = mat.length; // Only for square matrices

        // Swap elements across the diagonal
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                // Swap mat[i][j] with mat[j][i]
                int temp = mat[i][j];
                mat[i][j] = mat[j][i];
                mat[j][i] = temp;
            }
        }

        return mat;
    }

    public static void main(String[] args) {
        int[][] mat = {
            {1, 1, 1, 1},
            {2, 2, 2, 2},
            {3, 3, 3, 3},
            {4, 4, 4, 4}
        };

        int[][] result = transpose(mat);

        // Print result
        for (int[] row : result) {
            System.out.println(Arrays.toString(row));
        }
    }
}

/*
Time Complexity: O(n^2)
- We iterate through the upper triangle of the square matrix.

Space Complexity: O(1)
- The matrix is modified in-place with no extra space.
- Only works for square matrices.
*/

