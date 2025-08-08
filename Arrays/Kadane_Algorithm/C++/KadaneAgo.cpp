// KadaneAlgo.cpp
// Kadane's Algorithm — Optimized O(n)

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Function to find maximum subarray sum using Kadane's Algorithm
int maxSubarraySumKadane(vector<int>& arr) {
    int n = arr.size();
    int maxEndingHere = arr[0];
    int maxSoFar = arr[0];

    for (int i = 1; i < n; i++) {
        // Choose between starting a new subarray or extending previous one
        maxEndingHere = max(arr[i], maxEndingHere + arr[i]);
        maxSoFar = max(maxSoFar, maxEndingHere);
    }

    return maxSoFar;
}

int main() {
    vector<int> arr = {2, 3, -8, 7, -1, 2, 3};
    cout << "Maximum Subarray Sum (Kadane's Algorithm): " << maxSubarraySumKadane(arr) << endl;
    return 0;
}

/*
Time Complexity: O(n)  
Space Complexity: O(1)
*/
