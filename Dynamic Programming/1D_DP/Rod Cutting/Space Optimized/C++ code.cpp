#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int cutRod(vector<int>& price) {
    int n = price.size();
    vector<int> prev(n + 1);

    for (int p = 0; p <= n; p++) {
        prev[p] = p * price[0];
    }

    for (int i = 1; i < n; i++) {
        for (int p = 0; p <= n; p++) {
            int notTake = prev[p];
            int take = INT_MIN;
            int rodLen = i + 1;
            if (rodLen <= p)
                take = price[i] + prev[p - rodLen];
            prev[p] = max(notTake, take);
        }
    }

    return prev[n];
}

int main() {
    vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};
    cout << cutRod(price) << endl;
    return 0;
}
