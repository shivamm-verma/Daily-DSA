#include <iostream>
using namespace std;
int climbStairs(int n) {
    if (n <= 2) return n;
    return climbStairs(n - 1) + climbStairs(n - 2);
}
int main() {
    int n;
    cout << "Enter number of stairs: ";
    cin >> n;
    int result = climbStairs(n);
    cout << "Number of ways to climb " << n << " stairs: " << result << endl;
    
}
