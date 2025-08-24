import java.util.Scanner;
public class Java_code {
    public static int climbStairs(int n) {
        if (n <= 2) return n;
        return climbStairs(n - 1) + climbStairs(n - 2);
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter number of stairs: ");
        int n = scanner.nextInt();
        int result = climbStairs(n);
        System.out.println("Number of ways to climb " + n + " stairs: " + result);
    }
}
