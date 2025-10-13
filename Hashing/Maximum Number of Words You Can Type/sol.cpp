#include <iostream>
#include <unordered_set>
#include <sstream>
using namespace std;

class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char> broken(brokenLetters.begin(), brokenLetters.end());
        stringstream ss(text);
        string word;
        int count = 0;

        while (ss >> word) {
            bool canType = true;
            for (char ch : word) {
                if (broken.count(ch)) {
                    canType = false;
                    break;
                }
            }
            if (canType) count++;
        }

        return count;
    }
};

int main() {
    string text, brokenLetters;
    cout << "Enter the sentence: ";
    getline(cin, text);
    cout << "Enter broken letters (no spaces): ";
    cin >> brokenLetters;

    Solution sol;
    int result = sol.canBeTypedWords(text, brokenLetters);
    cout << "You can type " << result << " word(s) without using broken letters.\n";
    return 0;
}