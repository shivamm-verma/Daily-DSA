#include <iostream>
#include <stack>
using namespace std;
bool isPalindrome(int num) {
    if (num < 0) {
        return false;
    }
    if (num == 0) {
        return true;
    }
    stack<int> st;
    int originalNum = num;
    while (num > 0) {
        st.push(num % 10);
        num = num / 10;
    }
    while (!st.empty()) {
        if (st.top() != originalNum % 10) {
            return false;
        }
        st.pop();
        originalNum = originalNum / 10;
    }
    return true;
}
int main() {
    int num;
    cout << "Enter an integer: ";
    cin >> num;
    if (isPalindrome(num)) {
        cout << num << " is a palindrome." << endl;
    } else {
        cout << num << " is not a palindrome." << endl;
    }
    return 0;
} 