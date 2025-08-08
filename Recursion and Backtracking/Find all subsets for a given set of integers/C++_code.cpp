#include <iostream>
#include <vector>
using namespace std;
void findSubsets(vector<int>& nums, vector<vector<int>>& result, vector<int>& current, int index) {
    result.push_back(current);
    
    for (int i = index; i < nums.size(); i++) {
        current.push_back(nums[i]);
        findSubsets(nums, result, current, i + 1);
        current.pop_back();
    }
}
vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> current;
    findSubsets(nums, result, current, 0);
    return result;
}
int main() {
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    vector<vector<int>> result = subsets(nums);
    cout << "All subsets:" << endl;
    for (const auto& subset : result) {
        cout << "[";
        for (int i = 0; i < subset.size(); i++) {
            cout << subset[i];
            if (i < subset.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
    return 0;
} 