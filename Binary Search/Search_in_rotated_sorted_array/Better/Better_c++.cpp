#include<bits/stdc++.h>
using namespace std;

int findPivot(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        
        if (nums[mid] > nums[right]) {
            left = mid + 1; // Pivot is in right half
        } else {
            right = mid; // Pivot is in left half or at mid
        }
    }
    return left; // Pivot index (smallest element)
}

int binarySearch(vector<int>& nums, int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (nums[mid] == target) return mid;
        else if (nums[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int search(vector<int>& nums, int target) {
    if (nums.empty()) return -1;
    
    int n = nums.size();
    int pivot = findPivot(nums);
    
    // Search in the appropriate half
    if (target >= nums[pivot] && target <= nums[n - 1]) {
        return binarySearch(nums, pivot, n - 1, target); // Right half
    } else {
        return binarySearch(nums, 0, pivot - 1, target); // Left half
    }
}

int main(){
    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 0;
    int result = search(nums, target);
    cout << "Index of target " << target << ": " << result << endl;
    return 0;
}