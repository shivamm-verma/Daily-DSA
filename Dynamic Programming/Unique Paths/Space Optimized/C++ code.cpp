#include <iostream>
#include <vector>
using namespace std;

int uniquePaths(int m, int n) {
    vector<int> prev(n, 0);

    for (int i = 0; i < m; i++) {
        vector<int> temp(n, 0);
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0) {
                temp[j] = 1;
            } else {
                int up = (i > 0) ? prev[j] : 0;
                int left = (j > 0) ? temp[j - 1] : 0;
                temp[j] = up + left;
            }
        }
        prev = temp;
    }

    return prev[n - 1];
}

int main() {
    int m = 3, n = 7;
    cout << uniquePaths(m, n) << endl;
    return 0;
}
