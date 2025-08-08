import java.util.Arrays;

public class BruteForce {

    public static int[][] transpose(int[][] mat) {
        int rows = mat.length;
        int cols = mat[0].length;

        // Create a new matrix of size cols x rows
        int[][] result = new int[cols][rows];

        // Fill the transposed matrix
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result[j][i] = mat[i][j];
            }
        }

        return result;
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
Time Complexity: O(n * m)
- We iterate over each element once.

Space Complexity: O(n * m)
- A new matrix is created to store the result.
*/

