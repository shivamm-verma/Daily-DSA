#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int knapsack(vector<int>& wt, vector<int>& val, int capacity, int n) {
    vector<int> prev(capacity + 1, 0);

    for (int w = 0; w <= capacity; w++) {
        prev[w] = (w / wt[0]) * val[0];
    }

    for (int i = 1; i < n; i++) {
        for (int w = 0; w <= capacity; w++) {
            int notTake = prev[w];
            int take = INT_MIN;
            if (wt[i] <= w)
                take = val[i] + prev[w - wt[i]];
            prev[w] = max(notTake, take);
        }
    }

    return prev[capacity];
}

int main() {
    vector<int> val = {6, 1, 7, 7};
    vector<int> wt = {1, 3, 4, 5};
    int capacity = 8;
    cout << knapsack(wt, val, capacity, wt.size()) << endl;
    return 0;
}
