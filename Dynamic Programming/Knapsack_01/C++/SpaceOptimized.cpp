#include <vector>
#include <algorithm>

class Knapsack01Solver {
public:
    int solve(int capacity, const std::vector<int>& weights, const std::vector<int>& values) {
        int n = weights.size();
        std::vector<int> dp(capacity + 1, 0);

        for (int i = 0; i < n; ++i) {
            for (int w = capacity; w >= weights[i]; --w) {
                dp[w] = std::max(dp[w], values[i] + dp[w - weights[i]]);
            }
        }

        return dp[capacity];
    }
};


// Time Complexity: O(n * capacity)
// Space Complexity: O(capacity)