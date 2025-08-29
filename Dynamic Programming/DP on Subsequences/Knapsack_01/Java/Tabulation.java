public class Knapsack01Tabulation {

    public int solve(int n, int capacity, int[] weights, int[] values) {
        int[][] dp = new int[n + 1][capacity + 1];

        for (int i = 1; i <= n; i++) {
            for (int w = 0; w <= capacity; w++) {
                int exclude = dp[i - 1][w];
                int include = 0;
                if (weights[i - 1] <= w) {
                    include = values[i - 1] + dp[i - 1][w - weights[i - 1]];
                }

                dp[i][w] = Math.max(include, exclude);
            }
        }

        return dp[n][capacity];
    }
}

// Time Complexity: O(n * W)
// Space Complexity: O(n * W)


 /**
     * Public method to solve the 0/1 Knapsack problem.
     * @param w        current Capacity of knapsack
     * @param n        Total number of items.
     * @param capacity Maximum weight capacity of the knapsack.
     * @param weights  Array of weights of items.
     * @param values   Array of values of items.
     * @return Maximum value that can be achieved without exceeding the knapsack capacity.
     */