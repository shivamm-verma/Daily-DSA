import java.util.Arrays;

public class Knapsack01Memoization {

    public int solve(int n, int capacity, int[] weights, int[] values) {
        int[][] dp = new int[n][capacity + 1];
        
        for (int[] row : dp) {
            Arrays.fill(row, -1);
        }

        return knapsack(n - 1, capacity, weights, values, dp);
    }

    private int knapsack(int index, int remainingCapacity, int[] weights, int[] values, int[][] dp) {
        if (index == 0) {
            if (weights[0] <= remainingCapacity)
                return values[0];
            return 0;
        }

        if (dp[index][remainingCapacity] != -1)
            return dp[index][remainingCapacity];

        int exclude = knapsack(index - 1, remainingCapacity, weights, values, dp);

        int include = 0;
        if (weights[index] <= remainingCapacity) {
            include = values[index] + knapsack(index - 1, remainingCapacity - weights[index], weights, values, dp);
        }

        dp[index][remainingCapacity] = Math.max(include, exclude);
        return dp[index][remainingCapacity];
    }
}

// Time Complexity: O(n * W)
// Space Complexity: O(n * W)



  /**
     * Public method to initiate the 0/1 Knapsack solver.
     *
     * @param n        Total number of items.
     * @param capacity Maximum weight the knapsack can hold.
     * @param weights  Array of weights of the items.
     * @param values   Array of values of the items.
     * @return Maximum value that can be achieved without exceeding capacity.
     */

        /**
     * Recursive helper function for memoized knapsack.
     *
     * @param index              Current item index being considered.
     * @param remainingCapacity  Remaining capacity in the knapsack.
     * @param weights            Weight array.
     * @param values             Value array.
     * @param dp                 Memoization table.
     * @return                   Maximum value with current choices.
     */