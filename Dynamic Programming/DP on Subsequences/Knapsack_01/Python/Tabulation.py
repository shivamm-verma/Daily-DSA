class Knapsack01Tabulation:
    def solve(self, n, capacity, weights, values):
        # Create DP table
        dp = [[0] * (capacity + 1) for _ in range(n + 1)]

        for i in range(1, n + 1):
            for w in range(capacity + 1):
                exclude = dp[i - 1][w]
                include = 0
                if weights[i - 1] <= w:
                    include = values[i - 1] + dp[i - 1][w - weights[i - 1]]

                dp[i][w] = max(include, exclude)

        return dp[n][capacity]

#Time Complexity: O(n * W)
#Space Complexity: O(n * W)


# n         : Number of items available
# capacity  : Maximum weight capacity of the knapsack
# weights   : List of weights of the items
# values    : List of values of the items
# dp[i][w]  : Maximum value using first 'i' items and capacity 'w'
# i         : Current item index in the loop (1 to n)
# w         : Current weight capacity in the inner loop (0 to capacity)
# exclude   : Value when current item is not included
# include   : Value when current item is included (if it fits)
