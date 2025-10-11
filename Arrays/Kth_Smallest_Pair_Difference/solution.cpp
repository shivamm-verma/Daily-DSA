#include <bits/stdc++.h>
using namespace std;

// Function to count pairs with difference <= mid
int countPairs(vector<int>& nums, int mid) {
    int count = 0, left = 0;
    for (int right = 0; right < nums.size(); ++right) {
        while (nums[right] - nums[left] > mid) left++;
        count += right - left;
    }
    return count;
}

// Function to find Kth smallest pair difference
int smallestDistancePair(vector<int>& nums, int k) {
    /*
    Approach:
    1. Sort the array
    2. Binary search on the possible difference values (0 to max-min)
    3. For each mid, count pairs with difference <= mid using two pointers
    4. Narrow the search space based on the count

    Time Complexity: O(n log W), where W = max(nums) - min(nums)
    Space Complexity: O(1)
    */
    sort(nums.begin(), nums.end());
    int left = 0, right = nums.back() - nums.front();
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (countPairs(nums, mid) >= k) right = mid;
        else left = mid + 1;
    }
    return left;
}

int main() {
    int n, k;
    cout << "Enter number of elements and k: ";
    cin >> n >> k;
    vector<int> arr(n);
    cout << "Enter " << n << " numbers: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << "Kth Smallest Pair Difference: " << smallestDistancePair(arr, k) << endl;

    return 0;
}
