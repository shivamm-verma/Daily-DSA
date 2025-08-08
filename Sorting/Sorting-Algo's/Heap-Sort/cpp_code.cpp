#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int>& arr, int n, int i)
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= n && arr[largest] < arr[left]) {
        largest = left;
    }

    if (right <= n && arr[largest] < arr[right]) {
        largest = right;
    }

    if (largest != i) {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr, int n)
{
    int size = n;
    while (size > 1) {
        swap(arr[1], arr[size]);
        size--;
        heapify(arr, size, 1);
    }
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n + 1); // 1-based indexing, arr[0] unused

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    // Build max heap
    for (int i = n / 2; i > 0; i--) {
        heapify(arr, n, i);
    }

    cout << "Printing the array after heapify :: ";
    for (int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }

    heapSort(arr, n);

    cout << "\nPrinting the sorted array :: ";
    for (int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
