#include <bits/stdc++.h>
using namespace std;

bool isBitSet(int n, int i) {
    // Shift 1 to the left i times and perform bitwise AND
    return (n & (1 << i)) != 0;
}

int main() {
    int n, i;
    cin >> n >> i;

    if (isBitSet(n, i))
        cout << "Yes";
    else
        cout << "No";

    return 0;
}

/*
Time Complexity: O(1)
Space Complexity: O(1)
*/
