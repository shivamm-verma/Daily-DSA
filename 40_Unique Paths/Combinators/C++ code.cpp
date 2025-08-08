#include <iostream>
using namespace std;

int uniquePaths(int m, int n) {
    int N = m + n - 2;
    int r = m - 1;
    double res = 1.0;
    for (int i = 1; i <= r; i++) {
        res = res * (N - r + i) / i;
    }
    return (int)res;
}

int main() {
    int m = 3, n = 7;
    cout << uniquePaths(m, n) << endl;
    return 0;
}
