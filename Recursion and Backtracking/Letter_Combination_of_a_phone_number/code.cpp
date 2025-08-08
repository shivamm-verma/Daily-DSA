#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> keypad = {
    "", "", "abc", "def",
    "ghi", "jkl", "mno", "pqrs",
    "tuv", "wxyz"};
    
void solve(string digits, int index, string path, vector<string> &result)
{
    if (index == digits.size())
    {
        result.push_back(path);
        return;
    }
    string letters = keypad[digits[index] - '0'];
    for (char ch : letters)
    {
        solve(digits, index + 1, path + ch, result);
    }
}
vector<string> letterCombinations(string digits)
{
    vector<string> result;
    if (digits.empty())
        return result;
    solve(digits, 0, "", result);
    return result;
}

int main()
{
    string digits;
    cin >> digits;
    vector<string> combos = letterCombinations(digits);

    for (string s : combos)
    {
        cout << s << " ";
    }

    return 0;
}