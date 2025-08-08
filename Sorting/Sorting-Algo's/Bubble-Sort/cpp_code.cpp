#include <bits/stdc++.h>
using namespace std;



void bubble(int arr[], int n)
{
    
   
    for (int i = 0; i < n - 1; i++)
    {
        // Inner loop goes from start to the last unsorted element
        for (int j = 0; j < n - i - 1; j++)
        {
            // Compare current element with the next one
            if (arr[j] > arr[j + 1])
            {
                // Swap if they are in the wrong order
                swap(arr[j], arr[j + 1]);
            }
        }
        // After each iteration of this loop, the i-th largest element is at position n - i - 1
    }
}

int main()
{
    int n;
    cout << "Enter the size of an array :: ";
    cin >> n;
    int arr[n];

    cout << "Enter the elements of the array :: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Call bubble sort to sort the array
    bubble(arr, n);

    // Print the sorted array
    cout << "\nAfter sorting array :: \n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}