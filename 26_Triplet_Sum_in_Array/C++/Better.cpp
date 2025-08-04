#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// Function to check if any triplet sums up to the target using hashing
bool hasTripletSum(vector<int>& arr, int target) {
    int n = arr.size();

    // Fix the first element one by one
    for (int i = 0; i < n - 2; i++) {
        unordered_set<int> seen;  // Hash set for tracking complements

        // Now check for the remaining two elements using 2-sum logic
        for (int j = i + 1; j < n; j++) {
            int required = target - arr[i] - arr[j];

            if (seen.find(required) != seen.end()) {
                return true;
            }

            // Store current element as potential future pair element
            seen.insert(arr[j]);
        }
    }

    return false;
}

int main() {
    // Sample input
    vector<int> arr = {1, 4, 45, 6, 10, 8};
    int target = 13;

    // Function call
    if (hasTripletSum(arr, target)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}


/* 💡 Notes:
Time Complexity: O(n²)

Space Complexity: O(n)

More efficient than brute force and works well for moderately large arrays.*/