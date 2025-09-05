#include <bits/stdc++.h>
using namespace std;

bool isIsomorphic(string s, string t) {
    if (s.size() != t.size()) return false;

    int mapST[256] = {0};
    int mapTS[256] = {0};

    for (int i = 0; i < s.size(); i++) {
        char a = s[i], b = t[i];

        if (mapST[a] == 0 && mapTS[b] == 0) {
            mapST[a] = b;
            mapTS[b] = a;
        } else {
            if (mapST[a] != b || mapTS[b] != a) return false;
        }
    }
    return true;
}

int main() {
    string s, t;
    cin >> s >> t;
    cout << (isIsomorphic(s, t) ? "true" : "false") << endl;
    return 0;
}
