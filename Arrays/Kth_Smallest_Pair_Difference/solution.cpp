#include <iostream>
#include <vector>
#include <algorithm>

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
    sort(nums.begin(), nums.end());
    int left = 0, right = nums.back() - nums[0];
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (countPairs(nums, mid) >= k)
            right = mid;
        else
            left = mid + 1;
    }
    return left;
}

int main() {
    int n, k;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) cin >> nums[i];
    cout << "Enter k: ";
    cin >> k;

    cout << "Kth Smallest Pair Difference: " << smallestDistancePair(nums, k) << endl;
    return 0;
}
