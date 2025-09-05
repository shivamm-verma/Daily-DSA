#include <bits/stdc++.h>
using namespace std;

// Function to check if cows can be placed with at least 'dist' spacing
bool canPlace(vector<int>& stalls, int cows, int dist) {
    int count = 1;  // place first cow at first stall
    int last = stalls[0];
    
    for (int i = 1; i < stalls.size(); i++) {
        if (stalls[i] - last >= dist) {
            count++;
            last = stalls[i];
        }
        if (count >= cows) return true;
    }
    return false;
}

// Brute force solution
int aggressiveCows(vector<int>& stalls, int cows) {
    sort(stalls.begin(), stalls.end());
    int maxDist = stalls.back() - stalls.front();
    int ans = 0;

    // Try every possible distance from max to min
    for (int dist = maxDist; dist >= 1; dist--) {
        if (canPlace(stalls, cows, dist)) {
            ans = dist;
            break;
        }
    }
    return ans;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> stalls(n);
    for (int i = 0; i < n; i++) cin >> stalls[i];

    cout << "Brute Force Answer: " << aggressiveCows(stalls, k) << endl;
    return 0;
}

/*
Time Complexity:
- Sorting stalls: O(N log N)
- For each distance (maxDist → 1): O(maxDist × N)
- Overall: O(N log N + N × maxDist)  ❌ (very large when maxDist is big)

Space Complexity:
- O(1) extra space (apart from input array)
*/
