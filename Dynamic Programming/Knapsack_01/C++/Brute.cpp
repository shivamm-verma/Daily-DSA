#include <iostream>
#include <vector>
#include <algorithm>

class Knapsack01BruteForce {
public:
    int solve(int n, int capacity, const std::vector<int>& weights, const std::vector<int>& values) {
        return knapsack(n, capacity, weights, values);
    }

private:
    int knapsack(int index, int remainingCapacity, const std::vector<int>& weights, const std::vector<int>& values) {
        if (index == 0 || remainingCapacity == 0)
            return 0;

        if (weights[index - 1] > remainingCapacity)
            return knapsack(index - 1, remainingCapacity, weights, values);

        int include = values[index - 1] + knapsack(index - 1, remainingCapacity - weights[index - 1], weights, values);
        int exclude = knapsack(index - 1, remainingCapacity, weights, values);

        return std::max(include, exclude);
    }
};

// Time Complexity  O(2^n)
// Space Complexity O(n)
// Never Really Used 