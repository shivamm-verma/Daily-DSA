#include <iostream>
#include <vector>
#include <string>
using namespace std;

class KMP {
private:
    vector<int> computeLPS(const string& pattern) {
        int m = pattern.length();
        vector<int> lps(m, 0);
        int len = 0, i = 1;
        while (i < m) {
            if (pattern[i] == pattern[len]) lps[i++] = ++len;
            else if (len) len = lps[len - 1];
            else lps[i++] = 0;
        }
        return lps;
    }

public:
    vector<int> search(const string& text, const string& pattern) {
        vector<int> res;
        int n = text.length(), m = pattern.length();
        if (!m) return res;
        vector<int> lps = computeLPS(pattern);
        int i = 0, j = 0;
        while (i < n) {
            if (text[i] == pattern[j]) i++, j++;
            if (j == m) { res.push_back(i - j); j = lps[j - 1]; }
            else if (i < n && text[i] != pattern[j]) j ? j = lps[j - 1] : i++;
        }
        return res;
    }
};

int main() {
    string text, pattern;
    cout << "Enter text: ";
    getline(cin, text);
    cout << "Enter pattern: ";
    getline(cin, pattern);

    KMP kmp;
    vector<int> matches = kmp.search(text, pattern);

    if (matches.empty()) cout << "Pattern not found\n";
    else {
        cout << "Pattern found at indices: ";
        for (int i : matches) cout << i << " ";
        cout << endl;
    }
    return 0;
}
