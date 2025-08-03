
LETTER COMBINATION OF A PHONE NUMBER - EXPLAINED
===========================================

Problem:
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

Explanation of solution: 
Based on concepts of **Recursion and Backtracking.**

vector<string> keypad = {
    "",     "",     "abc",  "def",
    "ghi",  "jkl",  "mno",  "pqrs",
    "tuv",  "wxyz"
};
 
This maps the digits 0-9 to their corresponding strings.
keypad[2] = "abc" , keypad[3] = "def" and so on.

**Recursive Function: solve()**
void solve(string digits, int index, string path, vector<string>& result)
This is a backtracking function that builds combination character by character.

**Base Case**
if (index == digits.size())
{
    result.push_back(path);
    return;
}

When we've chosen a letter for every digit, we add the path (current combination) to the result list.

**Recursive Case**
string letters = keypad[digits[index] - '0'];
for (char ch : letters)
{
    solve(digits, index + 1, path + ch, result);
}

The process works as following:
#Convert the digit to an integer index (e.g., '2' - '0' = 2).
#Fetch the letters mapped to that digit from the keypad vector.
#For each letter:
    Add it to the current path (path + ch)
    Recurse to the next digit (index + 1)

**Driver Function**
vector<string> letterCombinations(string digits) - Initializes a result vector to hold combinations. Handles the edge case when input is empty.

**Main Function**
Takes input like 23
Calls the main combination function
Prints each combination

**Recap of Core Concepts Used:**
1. Backtracking
2. Recursive traversal
3. String manipulation
4. Digit-to-character mapping using a vector

**Example input and output**
Input - 23
Output - ad ae af bd be bf cd ce cf

**Time Complexity: O(4ⁿ)**

**Space Complexity: O(n × 4ⁿ)**
