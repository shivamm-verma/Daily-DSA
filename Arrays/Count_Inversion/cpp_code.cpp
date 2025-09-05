#include <bits/stdc++.h>
using namespace std;

// Function to merge two halves and count inversions
long long mergeAndCount(vector<int>& arr, int l, int mid, int r) {
    vector<int> left(arr.begin() + l, arr.begin() + mid + 1);
    vector<int> right(arr.begin() + mid + 1, arr.begin() + r + 1);

    int i = 0, j = 0, k = l;
    long long inv = 0;

    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
            inv += (left.size() - i); // all remaining elements in left are greater
        }
    }

    while (i < left.size()) arr[k++] = left[i++];
    while (j < right.size()) arr[k++] = right[j++];

    return inv;
}

// Recursive Merge Sort that counts inversions
long long mergeSortAndCount(vector<int>& arr, int l, int r) {
    long long inv = 0;
    if (l < r) {
        int mid = l + (r - l) / 2;
        inv += mergeSortAndCount(arr, l, mid);
        inv += mergeSortAndCount(arr, mid + 1, r);
        inv += mergeAndCount(arr, l, mid, r);
    }
    return inv;
}

int main() {
    // Example input
    vector<int> arr = {5, 4, 3, 2, 1};
    int n = arr.size();

    cout << "Array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    long long inversionCount = mergeSortAndCount(arr, 0, n - 1);

    cout << "Number of inversions: " << inversionCount << endl;

    return 0;
}
