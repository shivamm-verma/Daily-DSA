#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
class Solution {
public:
    int sumOfGoodNumbers(vector<int>& nums, int k) {
        int s=0;
        for(int i=0;i<nums.size();i++) {
            if(((i-k<0)||(nums[i]>nums[i-k]))&&
                    ((i+k>=nums.size())||(nums[i]>nums[i+k]))){
                s+=nums[i];
            }
        }
        return s;
    }
};
int main() {
    string input;
    cout << "Enter the array elements (space-separated): ";
    getline(cin, input);
    vector<int> nums;
    stringstream ss(input);
    int num;
    while (ss>>num) {
        nums.push_back(num);
    }
    int k;
    cout<<"Enter the value of k: ";
    cin>>k;
    Solution solution;
    int result=solution.sumOfGoodNumbers(nums, k);
    cout<<"Sum of good numbers: "<<result<<endl;
    return 0;
} 