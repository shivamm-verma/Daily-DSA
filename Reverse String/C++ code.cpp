#include <iostream>
#include <vector>
using namespace std;

void reverseString(vector<char>& s) {
    int l = 0, r = s.size() - 1;
    while (l < r) {
        char temp = s[l];
        s[l] = s[r];
        s[r] = temp;
        l++;
        r--;
    }
}

int main() {
    string str = "hello";
    vector<char> ch(str.begin(), str.end());
    reverseString(ch);
    for (char c : ch) cout << c; // Output: olleh
    return 0;
}
