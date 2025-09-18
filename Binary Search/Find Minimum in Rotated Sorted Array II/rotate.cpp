#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int lo = 0, hi = nums.size() - 1;

        // If array is not rotated
        if (nums[lo] < nums[hi]) {
            return nums[lo];
        }

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;

            if (nums[mid] > nums[hi]) {
                lo = mid + 1;
            } 
            else if (nums[mid] > nums[lo]) {
                hi = mid;
            } 
            else {
                hi--;
            }
        }
        return nums[lo];
    }
};

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution sol;
    cout << "Minimum element in rotated array: " << sol.findMin(nums) << endl;

    return 0;
}
