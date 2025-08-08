

#include <bits/stdc++.h>
using namespace std;

/*
    Function to merge two sorted subarrays:
    - First subarray: arr[low ... mid]
    - Second subarray: arr[mid+1 ... high]
    Merges both into a single sorted subarray.
*/
void mergeSort(vector<int> arr, int low, int mid, int high)
{
    vector<int> temp;    
    int left = low;   
    int right = mid + 1; 

   
    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);  
            left++;
        }
        else
        {
            temp.push_back(arr[right]);  
            right++;
        }
    }

    
    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}

/*
    Recursive Merge function:
    - Splits the array into two halves
    - Sorts each half
    - Merges them using mergeSort()
*/
void merge(vector<int> arr, int low, int high)
{
    if (low >= high)
        return;  

    int mid = (low + high) / 2;  

    merge(arr, low, mid);      
    merge(arr, mid + 1, high);  

    mergeSort(arr, low, mid, high);  
}


int main()
{
    int n=5;
    vector<int> arr;

    cout << "Enter the size of the array: ";
    cin >> n;


   
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Call merge sort function
    merge(arr, 0, n - 1);

    // Print the sorted array
    cout << "\nArray after sorting: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}