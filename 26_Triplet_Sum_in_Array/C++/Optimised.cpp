#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to check if any triplet sums up to the target using sorting + two-pointer
bool hasTripletSum(vector<int>& arr, int target) {
    int n = arr.size();

    // Sort the array to apply two-pointer technique
    sort(arr.begin(), arr.end());

    // Fix the first element and use two-pointer on the rest
    for (int i = 0; i < n - 2; i++) {
        int left = i + 1;
        int right = n - 1;

        while (left < right) {
            int sum = arr[i] + arr[left] + arr[right];

            if (sum == target)
                return true;
            else if (sum < target)
                left++;
            else
                right--;
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


/*  💡 Notes:
Time Complexity: O(n²)

Space Complexity: O(1)

Efficient and optimal approach for this problem.*/