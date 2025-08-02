import java.util.Scanner;

public class ClimbingStairsOptimized {
    public static int climbStairs(int n) {
        if (n == 0 || n == 1) return 1;

        int prev = 1, curr = 1;
        for (int i = 2; i <= n; i++) {
            int temp = curr;
            curr = prev + curr;
            prev = temp;
        }
        return curr;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of steps: ");
        int n = sc.nextInt();
        System.out.println("The total number of ways are: " + climbStairs(n));
    }
}
// This code implements an optimized solution for the Climbing Stairs problem using constant space.