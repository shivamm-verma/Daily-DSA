#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int result = 0;
        for (char c : columnTitle) {
            result = result * 26 + (c - 'A' + 1);
        }
        return result;
    }
};

int main() {
    string columnTitle;
    cout << "Enter Excel column title (e.g., 'AB'): ";
    cin >> columnTitle;
    
    Solution solution;
    cout << "Column Number is: " << solution.titleToNumber(columnTitle) << endl;

    return 0;
}
