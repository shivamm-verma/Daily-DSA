import java.util.*;
public class Java_code {
    public static int climbStairs(int n) {
        if (n <= 2) return n;
        int[] dp = new int[n + 1];
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
    public static int climbStairsOptimized(int n) {
        if (n <= 2) return n;
        int prev2 = 1;
        int prev1 = 2;
        int current;
        for (int i = 3; i <= n; i++) {
            current = prev1 + prev2;
            prev2 = prev1;
            prev1 = current;
        }
        return prev1;
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter number of stairs: ");
        int n = scanner.nextInt();
        int result1 = climbStairs(n);
        int result2 = climbStairsOptimized(n);
        System.out.println("Number of ways to climb " + n + " stairs (DP): " + result1);
        System.out.println("Number of ways to climb " + n + " stairs (Optimized): " + result2);
    }
}
