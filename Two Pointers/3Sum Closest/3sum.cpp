#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int res = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < nums.size() - 2; ++i) {
            int j = i + 1, k = nums.size() - 1;
            while (j < k) {
                int total = nums[i] + nums[j] + nums[k];
                if (abs(total - target) < abs(res - target)) {
                    res = total;
                }
                if (total > target) {
                    --k;
                } else if (total < target) {
                    ++j;
                } else {
                    return res;
                }
            }
        }
        return res;
    }
};

int main() {
    cout << "Enter integers separated by spaces: ";
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> nums;
    int num;
    while (ss >> num) {
        nums.push_back(num);
    }

    cout << "Enter target integer: ";
    int target;
    cin >> target;

    Solution sol;
    int result = sol.threeSumClosest(nums, target);
    cout << "The sum closest to the target is: " << result << endl;

    return 0;
}
