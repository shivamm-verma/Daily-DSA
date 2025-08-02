#include <iostream>
#include <vector>
#include <climits>  // For INT_MIN

int maxSubArray(const std::vector<int>& arr) {
    int maxSum = INT_MIN;
    int currSum = 0;

    for (int num : arr) {
        currSum += num;
        maxSum = std::max(maxSum, currSum);
        if (currSum < 0) {
            currSum = 0;
        }
    }

    return maxSum;
}