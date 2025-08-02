#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxProduct(vector<int>& arr, int n) {
    int currmax = arr[0], currmin = arr[0], maxp = arr[0];

    for(int i = 1; i < n; ++i) {
        int temp = max({arr[i], arr[i]*currmax, arr[i]*currmin});
        currmin = min({arr[i], arr[i]*currmax, arr[i]*currmin});
        currmax = temp;
        maxp = max(maxp, currmax);
    }
    return maxp;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int res = maxProduct(arr, n);
    cout << res << endl;

    return 0;
}
