#include <iostream>
using namespace std;

// Recursive C++ function to solve the Tower of Hanoi
void TowerOfHanoi(int n, char src, char dest, char aux) {
    if (n == 1) { // Base Case
        cout << "Move disk 1 from source " << src << " to destination " << dest << endl;
        return;
    }

    TowerOfHanoi(n - 1, src, aux, dest); // Recursive Call 1
    cout << "Move disk " << n << " from source " << src << " to destination " << dest << endl;
    TowerOfHanoi(n - 1, aux, dest, src); // Recursive Call 2
}

// Driver code
int main() {
    int n = 4; // Number of disks
    TowerOfHanoi(n, 'A', 'B', 'C'); // A, B, C are the names of rods
    return 0;
}

// Steps Followed:
// Move disk 1 from source A to destination C
// Move disk 2 from source A to destination B
// Move disk 1 from source C to destination B
// Move disk 3 from source A to destination C
// Move disk 1 from source B to destination A
// Move disk 2 from source B to destination C
// Move disk 1 from source A to destination C