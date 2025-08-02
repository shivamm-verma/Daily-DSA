#include <bits/stdc++.h>
using namespace std;
int climbing_stairs(int n)
{
    if (n <= 1)
        return 1;
    return climbing_stairs(n - 1) + climbing_stairs(n - 2);
}
int main()
{
    int n;
    cout << "Enter the number of steps: ";
    cin >> n;
    cout << "The total number of ways are:" << climbing_stairs(n) << endl;
    return 0;
}