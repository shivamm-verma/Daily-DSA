#include <iostream>
#include <vector>
using namespace std;

// Function to check if any triplet sums up to the target
bool hasTripletSum(vector<int>& arr, int target) {
    int n = arr.size();

    // Loop through every triplet combination
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                if (arr[i] + arr[j] + arr[k] == target) {
                    return true;
                }
            }
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



/*💡 Notes:
Time Complexity: O(n³) — not efficient for large inputs.

Space Complexity: O(1) — no extra space used.

Suitable for small arrays and demonstration purposes only. */