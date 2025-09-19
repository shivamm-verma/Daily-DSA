#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool isArrayAnagram(vector<int>& arr1, vector<int>& arr2) {
    if (arr1.size() != arr2.size()) return false;

    unordered_map<int, int> freq;

    // Count elements in arr1
    for (int num : arr1) {
        freq[num]++;
    }

    // Subtract using arr2
    for (int num : arr2) {
        if (freq.find(num) == freq.end()) return false;
        freq[num]--;
        if (freq[num] == 0) freq.erase(num);
    }

    return freq.empty();
}

int main() {
    vector<int> arr1 = {1, 2, 3};
    vector<int> arr2 = {3, 2, 1};
    vector<int> arr3 = {1, 2, 2};
    vector<int> arr4 = {2, 1, 1};

    cout << (isArrayAnagram(arr1, arr2) ? "true" : "false") << endl; // true
    cout << (isArrayAnagram(arr3, arr4) ? "true" : "false") << endl; // false
}
