#include <iostream>
#include <vector>
using namespace std;

void mysort(vector<int> &arr) {
    int low = 0, mid = 0;
    int high = arr.size() - 1;

    // Traverse the array until mid pointer crosses high
    while (mid <= high) {
        if (arr[mid] == 0) {
            // Place 0 at the beginning
            swap(arr[low++], arr[mid++]);
        }
        else if (arr[mid] == 1) {
            // Leave 1 in the middle
            mid++;
        }
        else {
            // Place 2 at the end
            swap(arr[mid], arr[high--]);
        }
    }
}

int main() {
    vector<int> arr = {0, 1, 2, 0, 1, 2};

    // Sort the array using Dutch National Flag Algorithm
    mysort(arr);

    // Output the sorted array
    for (int num : arr) {
        cout << num << " ";
    }

    cout << endl;
    return 0;
}