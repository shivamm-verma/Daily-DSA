#include <iostream>
#include <vector>
class Solution {
public:
    std::vector<int> getConcatenation(std::vector<int>& nums) {
        int n=nums.size();
        std::vector<int> ans(2 * n);
        for(int i=0;i<n;i++) {
            ans[i]=nums[i];
            ans[i+n]=nums[i];
        }
        return ans;
    }
};
int main() {
    int n;
    std::cout<<"Enter the size of the array: ";
    std::cin>>n;
    std::vector<int> nums(n);
    std::cout<<"Enter the elements of the array:" << std::endl;
    for (int i=0;i<n;i++) {
        std::cin>>nums[i];
    }
    Solution solution;
    std::vector<int> result=solution.getConcatenation(nums);
    std::cout<<"The concatenated array is: ";
    for (int i=0;i<result.size();i++) {
        std::cout<<result[i]<<" ";
    }
    std::cout << std::endl;
    return 0;
}