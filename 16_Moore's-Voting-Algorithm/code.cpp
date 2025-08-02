
#include <bits/stdc++.h>
using namespace std;

// function for implementing Moore's Voting Algorithm
void moore(vector<int> &arr, int n)
{
    int count = 0; //  keep track of current candidate count
    int el;        //  store the potential majority element
    int cnt = 0;   //  count actual occurrences of candidate

    // Step 1: Finding a candidate for majority element
    for (int i = 0; i < n; i++)
    {
        if (count == 0)
        {
            el = arr[i]; // setting current element as candidate
            count = 1;
        }
        else if (arr[i] == el)
        {
            count++; //if  Same as candidate → increment count
        }
        else
        {
            count--; // if Different → cancel out
        }
    }

    // Step 2: Verifying the candidate ( really majority?)
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == el) 
            cnt++;
    }

    // Step 3: Check if count > n/2
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