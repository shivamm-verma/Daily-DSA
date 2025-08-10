#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;

        for (int i = 0; i < nums.size() - 2; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int j = i + 1;
            int k = nums.size() - 1;

            while (j < k) {
                int total = nums[i] + nums[j] + nums[k];
                if (total == 0) {
                    result.push_back({nums[i], nums[j], nums[k]});
                    ++j;
                    --k;

                    while (j < k && nums[j] == nums[j - 1]) ++j;
                    while (j < k && nums[k] == nums[k + 1]) --k;
                } else if (total > 0) {
                    --k;
                } else {
                    ++j;
                }
            }
        }

        return result;
    }
};

int main() {
    vector<int> nums;
    int n, val;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter " << n << " integers separated by space: ";
    for (int i = 0; i < n; ++i) {
        cin >> val;
        nums.push_back(val);
    }

    Solution sol;
    vector<vector<int>> triplets = sol.threeSum(nums);

    cout << "Triplets that sum to zero:\n";
    for (const auto& triplet : triplets) {
        cout << "[";
        for (int i = 0; i < triplet.size(); ++i) {
            cout << triplet[i] << (i < triplet.size() - 1 ? ", " : "");
        }
        cout << "]\n";
    }

    return 0;
}
