import java.util.*;
public class Better {
    public static int celebrity(int[][] mat) {
        int n = mat.length;
        Stack<Integer> stack = new Stack<>();
        for (int i = 0; i < n; i++){
            stack.push(i);
        }
        while (stack.size() > 1) {
            int a = stack.pop();
            int b = stack.pop();
            if (mat[a][b] == 1) stack.push(b); 
            else stack.push(a);               
        }
        int candidate = stack.pop();
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
