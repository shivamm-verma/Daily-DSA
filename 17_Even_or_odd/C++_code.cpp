#include <iostream>
using namespace std;
bool isEven(int num) {
    return (num & 1) == 0;
}
int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;
    if (isEven(num)) {
        cout << num << " is even." << endl;
    } else {
        cout << num << " is odd." << endl;
    }
    return 0;
} 