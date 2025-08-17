#include <iostream>
using namespace std;

int noOfOneBits(int n) {
    int cnt = 0;
    for (int i = 0; i < 31; i++) {
        if (n & (1 << i)) {
            cnt++;
        }
    }
    return cnt;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Number of 1-bits: " << noOfOneBits(n) << endl;
    return 0;
}
