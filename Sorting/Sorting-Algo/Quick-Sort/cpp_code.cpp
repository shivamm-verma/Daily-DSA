#include <bits/stdc++.h>  
using namespace std;


 
int part(int arr[], int low, int high)
{
    int pivot = arr[low]; 
    int i = low;          
    int j = high;          

    
    while (i < j)
    {
        
        while (arr[i] <= pivot && i <= high - 1)
        {
            i++;
        }
         
        while (arr[j] > pivot && j >= low + 1)
        {
            j--;
        }

         
        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    }

    
    swap(arr[low], arr[j]);

   
    return j;
}

 
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
         
        int prevIdx = part(arr, low, high);

        
        quickSort(arr, low, prevIdx - 1);

        
        quickSort(arr, prevIdx + 1, high);
    }
}

int main()
{
    int n;
    cin >> n;  

    int arr[n]; 

    
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    
    quickSort(arr, 0, n - 1);

   
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}