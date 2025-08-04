#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int cutRod(vector<int>& price, int ind, int n) {
    if (ind == 0)
        return n * price[0];
    
    int notTake = cutRod(price, ind - 1, n);
    int take = INT_MIN;
    int rodLen = ind + 1;
    if (rodLen <= n)
        take = price[ind] + cutRod(price, ind, n - rodLen);
    
    return max(take, notTake);
}

int main() {
    vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};
    int n = price.size();
    cout << cutRod(price, n - 1, n) << endl;
    return 0;
}
