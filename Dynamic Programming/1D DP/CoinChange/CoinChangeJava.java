import java.util.*;
public class CoinChangeJava {
    public static int minCoins(int[] coins, int X) {
        int n = coins.length;
        int[] dp = new int[X + 1];
        Arrays.fill(dp, X + 1); 
        dp[0] = 0;
        for (int i = 1; i <= X; i++) {
            for (int coin : coins) {
                if (coin <= i) {
                    dp[i] = Math.min(dp[i], 1 + dp[i - coin]);
                }
            }
        }
        return (dp[X] > X) ? -1 : dp[X];
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number of coin types: ");
        int n = sc.nextInt();
        int[] coins = new int[n];
        System.out.println("Enter coin denominations: ");
        for (int i = 0; i < n; i++) {
            coins[i] = sc.nextInt();
        }
        System.out.print("Enter the amount X: ");
        int X = sc.nextInt();
        int result = minCoins(coins, X);
        System.out.println("Minimum coins required: " + result);
    }
}
