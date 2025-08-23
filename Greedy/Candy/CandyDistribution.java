import java.util.*;

public class CandyDistribution {
    public static int candy(int[] ratings) {
        int n = ratings.length;
        int[] candies = new int[n];
        Arrays.fill(candies, 1);

        // Left to right
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }

        // Right to left
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = Math.max(candies[i], candies[i + 1] + 1);
            }
        }

        int total = 0;
        for (int c : candies) total += c;
        return total;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter ratings separated by spaces: ");
        String[] input = sc.nextLine().split(" ");
        int[] ratings = new int[input.length];
        for (int i = 0; i < input.length; i++) {
            ratings[i] = Integer.parseInt(input[i]);
        }

        System.out.println("Minimum candies needed: " + candy(ratings));
    }
}
