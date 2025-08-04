#include<bits/stdc++.h>
using namespace std;

int search(vector<int>& nums, int target) {
    // Linear search through the array
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == target) {
            return i;
        }
    }
    return -1; // Target not found
}

int main(){
    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 0;
    int result = search(nums, target);
    cout << "Index of target " << target << ": " << result << endl;
    return 0;
}