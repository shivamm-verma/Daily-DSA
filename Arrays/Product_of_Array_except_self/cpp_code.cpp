#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n, 1);

        // Step 1: Prefix product
        int prefix = 1;
        for (int i = 0; i < n; i++) {
            answer[i] = prefix;
            prefix *= nums[i];
        }

        // Step 2: Suffix product
        int suffix = 1;
        for (int i = n - 1; i >= 0; i--) {
            answer[i] *= suffix;
            suffix *= nums[i];
        }

        return answer;
    }
};

// Example usage
#include <iostream>
int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 4};
    vector<int> result = sol.productExceptSelf(nums);

    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}
