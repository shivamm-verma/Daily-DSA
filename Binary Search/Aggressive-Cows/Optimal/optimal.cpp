#include <bits/stdc++.h>
using namespace std;

// Function to check if we can place cows with at least 'dist' distance
bool canPlace(vector<int> &stalls, int cows, int dist) {
    int count = 1; 
    int lastPos = stalls[0];

    for (int i = 1; i < stalls.size(); i++) {
        if (stalls[i] - lastPos >= dist) {
            count++;
            lastPos = stalls[i];
        }
        if (count >= cows) return true;
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int cows) {
    sort(stalls.begin(), stalls.end());
    int n = stalls.size();

    int low = 1, high = stalls[n-1] - stalls[0];
    int ans = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (canPlace(stalls, cows, mid)) {
            ans = mid;
            low = mid + 1;  // Try for bigger distance
        } else {
            high = mid - 1; // Try smaller distance
        }
    }
    return ans;
}

int main() {
    vector<int> stalls = {1, 2, 8, 4, 9};
    int cows = 3;
    cout << "Maximum Minimum Distance: " << aggressiveCows(stalls, cows) << endl;
    return 0;
}

/*
Time Complexity:
- Sorting: O(N log N)
- Binary Search: O(log(max(stalls) - min(stalls)))
- Checking placement: O(N) for each binary search step
Overall: O(N log N + N log(maxDistance))

Space Complexity: O(1) (ignoring sorting space)
*/
