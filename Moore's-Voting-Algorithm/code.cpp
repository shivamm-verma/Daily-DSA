
#include <bits/stdc++.h>
using namespace std;

// function for implementing Moore's Voting Algorithm
void moore(vector<int> &arr, int n)
{
    int count = 0; 
    int el;        
    int cnt = 0;   


    for (int i = 0; i < n; i++)
    {
        if (count == 0)
        {
            el = arr[i]; 
            count = 1;
        }
        else if (arr[i] == el)
        {
            count++; 
        }
        else
        {
            count--; 
        }
    }

    
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == el) 
            cnt++;
    }

    
    if (cnt > (n / 2))
    {
        cout << "Majority element is :: " << el << endl;
    }
    else
    {
        cout << "No majority element" << endl;
    }
}


int main()
{
    int n;


    cout << "Enter the size of an array :: ";
    cin >> n;

    vector<int> arr(n);


    cout << "Enter the elements for the array :: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }


    moore(arr, n);

    return 0;
}