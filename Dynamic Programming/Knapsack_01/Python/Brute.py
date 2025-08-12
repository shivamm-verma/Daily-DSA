class Knapsack01BruteForce:
    def solve(self, n, capacity, weights, values):
        return self._knapsack(n, capacity, weights, values)

    def _knapsack(self, index, remaining_capacity, weights, values):
        if index == 0 or remaining_capacity == 0:
            return 0

        if weights[index - 1] > remaining_capacity:
            return self._knapsack(index - 1, remaining_capacity, weights, values)

        include = values[index - 1] + self._knapsack(index - 1, remaining_capacity - weights[index - 1], weights, values)

        exclude = self._knapsack(index - 1, remaining_capacity, weights, values)

        return max(include, exclude)


#  Time Complexity  O(2^n)
#  Space Complexity O(n)
# Never Really Used 