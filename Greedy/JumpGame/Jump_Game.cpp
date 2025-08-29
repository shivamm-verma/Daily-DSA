// Greedy: track the furthest reachable index.
// Time: O(n), Space: O(1)
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            if (i > maxReach) return false;
            maxReach = max(maxReach, i + nums[i]);
            if (maxReach >= n - 1) return true;
        }
        return true;
    }
};

int main() {
    Solution solution;
    vector<int> nums1 = {2, 3, 1, 1, 4};
    vector<int> nums2 = {3, 2, 1, 0, 4};
    
    cout << (solution.canJump(nums1) ? "true" : "false") << endl;  // true
    cout << (solution.canJump(nums2) ? "true" : "false") << endl;  // false
}
