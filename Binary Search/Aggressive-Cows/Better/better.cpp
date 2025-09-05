#include <bits/stdc++.h>
using namespace std;

bool canPlace(vector<int>& stalls, int cows, int dist) {
    int count = 1, last = stalls[0];
    for (int i = 1; i < stalls.size(); i++) {
        if (stalls[i] - last >= dist) {
            count++;
            last = stalls[i];
        }
        if (count >= cows) return true;
    }
    return false;
}

int aggressiveCows(vector<int>& stalls, int cows) {
    sort(stalls.begin(), stalls.end());
    int n = stalls.size();
    int low = 1, high = stalls[n - 1] - stalls[0];
    int ans = 0;

    // Better: linear search from high to low
    for (int dist = high; dist >= 1; dist--) {
        if (canPlace(stalls, cows, dist)) {
            ans = dist;
            break; // stop at first valid maximum distance
        }
    }
    return ans;
}

int main() {
    vector<int> stalls = {1, 2, 8, 4, 9};
    int cows = 3;
    cout << aggressiveCows(stalls, cows) << endl;
    return 0;
}

/*
Time Complexity: O(N * (max(stall) - min(stall))) in worst case,
but usually faster since we stop early.
Space Complexity: O(1)
*/
