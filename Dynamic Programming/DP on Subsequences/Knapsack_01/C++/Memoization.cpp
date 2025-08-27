#include <vector>
#include <algorithm>

class Knapsack01Solver {
public:
    int solve(int itemCount, int capacity, const std::vector<int>& weights, const std::vector<int>& values) {
        std::vector<std::vector<int>> dp(itemCount, std::vector<int>(capacity + 1, -1));
        return knapsack(itemCount - 1, capacity, weights, values, dp);
    }

private:
    int knapsack(int index, int remainingCapacity,
                 const std::vector<int>& weights,
                 const std::vector<int>& values,
                 std::vector<std::vector<int>>& dp) {
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

        dp[index][remainingCapacity] = std::max(include, exclude);
        return dp[index][remainingCapacity];
    }
};



//Time Complexity: O(n * W)
//Space Complexity: O(n * W) 


 /**
     * Public function to start the knapsack solver.
     *
     * @param itemCount Number of items available
     * @param capacity  Maximum weight capacity of the knapsack
     * @param weights   Vector containing weights of items
     * @param values    Vector containing values of items
     * @return          Maximum value that can be achieved within the given capacity
     */

 /**
     * Recursive helper function that uses memoization to solve subproblems.
     *
     * @param index              Current item index being considered
     * @param remainingCapacity  Remaining weight capacity in the knapsack
     * @param weights            Vector of item weights
     * @param values             Vector of item values
     * @param dp                 2D vector for memoization of computed results
     * @return                   Maximum value achievable with given index and remaining capacity
     */