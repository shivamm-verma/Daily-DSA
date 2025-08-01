import java.util.Scanner;

public class ClimbingStairs {
    public static int climbingStairs(int n) {
        if (n <= 1) return 1;
        return climbingStairs(n - 1) + climbingStairs(n - 2);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of steps: ");
        int n = sc.nextInt();
        int totalWays = climbingStairs(n);
        System.out.println("The total number of ways are: " + totalWays);
    }
}
