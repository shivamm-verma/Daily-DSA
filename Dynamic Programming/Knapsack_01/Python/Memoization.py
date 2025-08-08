class Knapsack01Memoization:
    def solve(self, n, capacity, weights, values):
        
        dp = [[-1] * (capacity + 1) for _ in range(n)]
        return self._knapsack(n - 1, capacity, weights, values, dp)

    def _knapsack(self, index, remaining_capacity, weights, values, dp):
        
        if index == 0:
            if weights[0] <= remaining_capacity:
                return values[0]
            return 0

        if dp[index][remaining_capacity] != -1:
            return dp[index][remaining_capacity]

        exclude = self._knapsack(index - 1, remaining_capacity, weights, values, dp)

        include = 0
        if weights[index] <= remaining_capacity:
            include = values[index] + self._knapsack(
                index - 1, remaining_capacity - weights[index], weights, values, dp
            )

       
        dp[index][remaining_capacity] = max(include, exclude)
        return dp[index][remaining_capacity]


#Time Complexity: O(n * W)
#Space Complexity: O(n * W)



 
        # Solves the 0/1 Knapsack problem using top-down memoization (recursion + caching).

        # :param n: Number of items available
        # :param capacity: Maximum weight capacity of the knapsack
        # :param weights: List of weights for each item
        # :param values: List of values for each item
        # :return: Maximum value that can be achieved within given capacity
 

        # Recursive helper function to solve the knapsack problem.

        # :param index: Current item index being considered (0-based)
        # :param remaining_capacity: Remaining weight capacity of the knapsack
        # :param weights: List of item weights
        # :param values: List of item values
        # :param dp: 2D list for memoization
        # :return: Maximum value possible with current constraints
