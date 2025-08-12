#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> map;

    for (const string& s : strs) {
        string key = s;
        sort(key.begin(), key.end());
        map[key].push_back(s);
    }

    vector<vector<string>> result;
    for (const auto& entry : map) {
        result.push_back(entry.second);
    }

    return result;
}

int main() {
    int n;
    cout << "Size of array: ";
    cin >> n;

    vector<string> strs(n);
    cout << "Enter space-separated strings: ";
    for (int i = 0; i < n; ++i) {
        cin >> strs[i];
    }

    vector<vector<string>> grouped = groupAnagrams(strs);
    cout << "Grouped Anagrams:\n";
    for (const auto& group : grouped) {
        cout << "[ ";
        for (const string& word : group) {
            cout << word << " ";
        }
<<<<<<< HEAD
        cout << "]\n";
=======
        cout << "]";
>>>>>>> 25bcd466af18b3b64323a03cbd2d20735bd0c30b
    }

    return 0;
}