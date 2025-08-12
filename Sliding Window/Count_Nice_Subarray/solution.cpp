#include <bits/stdc++.h>
using namespace std;

int countAtMostK(vector<int>& nums, int k) {
    int left = 0, odd = 0;
    int count = 0;

    for (int right = 0; right < nums.size(); right++) {
        if (nums[right] % 2 == 1) odd++;

        while (odd > k) {
            if (nums[left] % 2 == 1) odd--;
            left++;
        }
        count += right - left + 1;
    }
    return count;
}

int numberOfSubarrays(vector<int>& nums, int k) {
    return countAtMostK(nums, k) - countAtMostK(nums, k - 1);
}

int main() {
    vector<int> nums = {1, 1, 2, 1, 1};
    int k = 3;
    cout << numberOfSubarrays(nums, k) << endl;
    return 0;
}
