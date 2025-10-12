#include <bits/stdc++.h>
using namespace std;

int totalFruits(vector<int>& arr) {
    unordered_map<int, int> count;
    int left = 0, maxFruits = 0;

    for (int right = 0; right < arr.size(); right++) {
        count[arr[right]]++;

        while (count.size() > 2) {
            count[arr[left]]--;
            if (count[arr[left]] == 0) count.erase(arr[left]);
            left++;
        }

        maxFruits = max(maxFruits, right - left + 1);
    }

    return maxFruits;
}

int main() {
    int n;
    cout << "Enter number of fruits: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter fruits array: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << "Maximum fruits collected: " << totalFruits(arr) << endl;
    return 0;
}
