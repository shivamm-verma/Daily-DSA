
#include <iostream> 
using namespace std;

// Insertion sort function
void insertion(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i]; // Current element to be inserted
        int j = i - 1;

        // Shift elements of arr[0..i-1], that are greater than key
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j]; // Shift element to the right
            j--;
        }
        arr[j + 1] = key; // Place key in its correct position
    }
}

int main()
{
    int n;

    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n]; // You can use vector<int> arr(n); for better practice

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }


    insertion(arr, n);


    cout << "\nArray after sorting: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}