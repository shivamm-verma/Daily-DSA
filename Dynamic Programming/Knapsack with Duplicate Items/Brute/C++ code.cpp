#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int knapsack(int ind, vector<int>& wt, vector<int>& val, int capacity) {
    if (ind == 0)
        return (capacity / wt[0]) * val[0];

    int notTake = knapsack(ind - 1, wt, val, capacity);
    int take = INT_MIN;
    if (wt[ind] <= capacity)
        take = val[ind] + knapsack(ind, wt, val, capacity - wt[ind]);

    return max(notTake, take);
}

int main() {
    vector<int> val = {6, 1, 7, 7};
    vector<int> wt = {1, 3, 4, 5};
    int capacity = 3;
    cout << knapsack(wt.size() - 1, wt, val, capacity) << endl;
    return 0;
}
