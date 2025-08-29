import java.util.*;
public class Optimal {
    public static int celebrity(int[][] mat) {
        int n = mat.length, candidate = 0;
        for (int i = 1; i < n; i++) {
            if (mat[candidate][i] == 1) candidate = i;
        }
        for (int i = 0; i < n; i++) {
            if (i != candidate && (mat[candidate][i] == 1 || mat[i][candidate] == 0)) {
                return -1;
            }
        }
        return candidate;
    }

    public static void main(String[] args) {
        int[][] mat = {
            {1, 1, 0},
            {0, 1, 0},
            {0, 1, 1}
        };
        int result = celebrity(mat);
        if (result == -1) {
            System.out.println("No celebrity found.");
        } else {
            System.out.println("Celebrity is person: " + result);
        }
    }
}
