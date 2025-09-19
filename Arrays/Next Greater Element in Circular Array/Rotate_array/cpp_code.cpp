#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;

        reverse(nums, 0, n - k - 1);
        reverse(nums, n - k, n - 1);
        reverse(nums, 0, n - 1);
    }

    void reverse(vector<int>& nums, int start, int end) {
        while (start <= end) {
            swap(nums[start], nums[end]);
            start++;
            end--;
        }
    }
};
