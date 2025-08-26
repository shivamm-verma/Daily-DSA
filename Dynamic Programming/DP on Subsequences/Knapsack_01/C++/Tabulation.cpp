
#include <vector>
#include <algorithm>


class Knapsack01TabulationSolver {
public:
   
    int solve(int itemCount, int capacity, const std::vector<int>& weights, const std::vector<int>& values) {
        std::vector<std::vector<int>> dp(itemCount + 1, std::vector<int>(capacity + 1, 0));

        for (int i = 1; i <= itemCount; ++i) {
            for (int w = 0; w <= capacity; ++w) {
                int exclude = dp[i - 1][w];
                int include = 0;
                if (weights[i - 1] <= w) {
                    include = values[i - 1] + dp[i - 1][w - weights[i - 1]];
                }
                dp[i][w] = std::max(include, exclude);
            }
        }
        return dp[itemCount][capacity];
    }
};


//Time Complexity: O(n * W)
//Space Complexity: O(n * W)


 /**
     * Solves the 0/1 Knapsack problem.
     *
     * @param itemCount Number of items
     * @param capacity  Capacity of the knapsack
     * @param weights   Vector of item weights
     * @param values    Vector of item values
     * @return          Maximum total value within given capacity
     */