#include <iostream>
#include <vector>
using namespace std;

vector<int> sumZero(int n) {
    vector<int> result(n);
    for (int i = 0; i < n / 2; ++i) {
        result[i] = i + 1;
        result[n - 1 - i] = -(i + 1);
    }
    if (n % 2 != 0) {
        result[n / 2] = 0;
    }
    return result;
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    vector<int> res = sumZero(n);
    cout << "Array with sum zero:\n";
    for (int num : res) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}