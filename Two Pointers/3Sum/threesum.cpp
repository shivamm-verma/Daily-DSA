#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;

    for (int i = 0; i < nums.size() - 2; ++i) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        int j = i + 1, k = nums.size() - 1;
        while (j < k) {
            int total = nums[i] + nums[j] + nums[k];
            if (total == 0) {
                res.push_back({nums[i], nums[j], nums[k]});
                ++j;
                --k;
                while (j < k && nums[j] == nums[j - 1]) ++j;
                while (j < k && nums[k] == nums[k + 1]) --k;
            } else if (total < 0) {
                ++j;
            } else {
                --k;
            }
        }
    }

    return res;
}

int main() {
    vector<int> nums;
    int num;
    cout << "Enter integers separated by spaces (end with non-integer): ";
    while (cin >> num) {
        nums.push_back(num);
    }

    vector<vector<int>> result = threeSum(nums);
    cout << "\nUnique triplets that sum to zero:\n";
    for (const auto& triplet : result) {
        cout << "[" << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << "]\n";
    }

    return 0;
}
