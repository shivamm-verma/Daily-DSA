
#include<bits/stdc++.h>
using namespace std;
void selection(int arr[], int n)
{
    // Loop through each element of the array
    for (int i = 0; i < n - 1; i++)
    {
        // Assume the current element is the minimum
        int min = i;

        // Find the index of the smallest element in the remaining unsorted array
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j; // Update index of minimum element
            }
        }

        // Swap the found minimum element with the first element of the unsorted part
        if (min != i)
        {
            swap(arr[i], arr[min]);
        }
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

    //  calling selection sort

    selection(arr, n);
    // Print the sorted array
    cout << "\nAfter sorting array :: \n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}