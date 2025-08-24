#include <bits/stdc++.h>
using namespace std;

pair<int,int> findMissingRepeating(vector<int>& nums) {
    int n = nums.size();
    int repeating = -1, missing = -1;
    for (int i = 1; i <= n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (nums[j] == i) count++;
        }
        if (count == 2) repeating = i;
        else if (count == 0) missing = i;
    }
    return {repeating, missing};
}

int main() {
    vector<int> nums = {3,1,2,5,3};
    auto ans = findMissingRepeating(nums);
    cout << "Repeating: " << ans.first << " Missing: " << ans.second;
}
