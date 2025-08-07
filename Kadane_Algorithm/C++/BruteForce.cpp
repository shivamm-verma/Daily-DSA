// KadaneAlgo.cpp
// Brute Force Approach — O(n^2)

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Function to find maximum subarray sum using brute force
int maxSubarraySumBruteForce(vector<int>& arr) {
    int n = arr.size();
    int maxSum = INT_MIN;

    // Outer loop for starting point of subarray
    for (int i = 0; i < n; i++) {
        int currSum = 0;

        // Inner loop for ending point of subarray
        for (int j = i; j < n; j++) {
            currSum += arr[j];
            maxSum = max(maxSum, currSum);
        }
    }

    return maxSum;
}

int main() {
    vector<int> arr = {2, 3, -8, 7, -1, 2, 3};
    cout << "Maximum Subarray Sum (Brute Force): " << maxSubarraySumBruteForce(arr) << endl;
    return 0;
}

/*
Time Complexity: O(n^2)  
Space Complexity: O(1)
*/
