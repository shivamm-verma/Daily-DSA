#include <vector>
class Solution {
public:
    int longestOnes(std::vector<int>& nums, int k) {
        int zeros = 0, maxLen = 0, i = 0, j = 0;
        int n = nums.size();

        while(i < n && j < n) {
            if(nums[j] == 1) {
                j++;
            } else if(nums[j] == 0) {
                zeros++;
                j++;
            }

            while(i < n && zeros > k) {
                if(nums[i] == 0) zeros--;
                i++;
            }

            maxLen = std::max(maxLen, j - i);
        }

        return maxLen;
    }
};
