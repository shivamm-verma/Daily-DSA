#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int knapsack(int ind, vector<int>& wt, vector<int>& val, int capacity, vector<vector<int>>& dp) {
    if (ind == 0)
        return (capacity / wt[0]) * val[0];
    
    if (dp[ind][capacity] != -1)
        return dp[ind][capacity];

    int notTake = knapsack(ind - 1, wt, val, capacity, dp);
    int take = INT_MIN;
    if (wt[ind] <= capacity)
        take = val[ind] + knapsack(ind, wt, val, capacity - wt[ind], dp);
    
    return dp[ind][capacity] = max(notTake, take);
}

int main() {
    vector<int> val = {6, 1, 7, 7};
    vector<int> wt = {1, 3, 4, 5};
    int capacity = 8;
    int n = wt.size();

    // Initialize dp array with -1
    vector<vector<int>> dp(n, vector<int>(capacity + 1, -1));

    cout << knapsack(n - 1, wt, val, capacity, dp) << endl;
    return 0;
}
