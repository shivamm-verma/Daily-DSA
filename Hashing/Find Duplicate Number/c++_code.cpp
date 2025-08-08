#include <iostream>
#include <unordered_set>
using namespace std;

int findDuplicate(int nums[], int n) {
    unordered_set<int> seen;
    for (int i = 0; i < n; ++i) {
        if (seen.find(nums[i]) != seen.end()) {
            return nums[i];
        }
        seen.insert(nums[i]);
    }
    return -1; 
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int nums[n];
    cout << "Enter the elements (one duplicate expected): ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    int duplicate = findDuplicate(nums, n);
    cout << "Duplicate number is: " << duplicate << endl;

    return 0;
}
