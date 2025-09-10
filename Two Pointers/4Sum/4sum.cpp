#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    int n = nums.size();

    for (int i = 0; i < n - 3; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        for (int j = i + 1; j < n - 2; j++) {
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;
            int l = j + 1, r = n - 1;
            while (l < r) {
                long long total = (long long)nums[i] + nums[j] + nums[l] + nums[r];
                if (total == target) {
                    res.push_back({nums[i], nums[j], nums[l], nums[r]});
                    l++;
                    r--;
                    while (l < r && nums[l] == nums[l - 1]) l++;
                    while (l < r && nums[r] == nums[r + 1]) r--;
                } else if (total < target) {
                    l++;
                } else {
                    r--;
                }
            }
        }
    }
    return res;
}

int main() {
    int n, target;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter array elements:\n";
    for (int i = 0; i < n; i++) cin >> nums[i];

    cout << "Enter target sum: ";
    cin >> target;

    vector<vector<int>> result = fourSum(nums, target);
    cout << "Quadruplets that sum to target:\n";
    for (auto& quad : result) {
        for (int num : quad) cout << num << " ";
        cout << "\n";
    }

    return 0;
}
