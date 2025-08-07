#include <iostream>
#include <algorithm>
using namespace std;

bool isAnagram(string s, string t) {
    if (s.length() != t.length()) return false;

    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    return s == t;
}

int main() {
    cout << boolalpha << isAnagram("anagram", "nagaram") << endl; // true
    cout << boolalpha << isAnagram("rat", "car") << endl;         // false
    return 0;
}
