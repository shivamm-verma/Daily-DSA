#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Ensure nums1 is the smaller array
        if (nums1.size() > nums2.size()) 
            return findMedianSortedArrays(nums2, nums1);

        int m = nums1.size(), n = nums2.size();
        int total = m + n;
        int half = total / 2;

        int left = 0, right = m;
        while (left <= right) {
            int mid1 = (left + right) / 2;      // partition for nums1
            int mid2 = half - mid1;             // partition for nums2

            int l1 = (mid1 > 0) ? nums1[mid1 - 1] : INT_MIN;
            int r1 = (mid1 < m) ? nums1[mid1] : INT_MAX;
            int l2 = (mid2 > 0) ? nums2[mid2 - 1] : INT_MIN;
            int r2 = (mid2 < n) ? nums2[mid2] : INT_MAX;

            if (l1 <= r2 && l2 <= r1) {
                // Found correct partition
                if (total % 2 == 0) {
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                } else {
                    return min(r1, r2);
                }
            } 
            else if (l1 > r2) {
                right = mid1 - 1; // move left
            } 
            else {
                left = mid1 + 1;  // move right
            }
        }
        return 0.0; // Should never reach here
    }
};

int main(){
    Solution sol;
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    cout << sol.findMedianSortedArrays(nums1, nums2) << endl; // Output: 2.0

    nums1 = {1, 2};
    nums2 = {3, 4};
    cout << sol.findMedianSortedArrays(nums1, nums2) << endl; // Output: 2.5

    return 0;
}