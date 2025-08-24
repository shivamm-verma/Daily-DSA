import java.util.*;

public class Brute_force {
    public static int celebrity(int[][] mat) {
        int n = mat.length;
        for (int i = 0; i < n; i++) {
            boolean knowsSomeone = false;
            boolean knownByEveryone = true;
            for (int j = 0; j < n; j++) {
                if (i != j && mat[i][j] == 1) knowsSomeone = true;
                if (i != j && mat[j][i] == 0) knownByEveryone = false;
            }
            if (!knowsSomeone && knownByEveryone) return i;
        }
        return -1;
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
 