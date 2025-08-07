#include <iostream>
using namespace std;

int uniquePaths(int i, int j) {
    if (i == 0 && j == 0)
        return 1;
    if (i < 0 || j < 0)
        return 0;
    int up = uniquePaths(i - 1, j);
    int left = uniquePaths(i, j - 1);
    return up + left;
}

int main() {
    int m = 3, n = 7;
    cout << uniquePaths(m - 1, n - 1) << endl;
    return 0;
}
