## ✅ DSA Question: To print all letter combination of a phone number 


## Problem
Given a string containing digits from 2 to 9, return all possible letter combinations that the number could represent. Return the answer in any order.

Mapping of digits - 2 -> abc  
                    3 -> def  
                    4 -> ghi  
                    5 -> jkl  
                    6 -> mno  
                    7 -> pqrs  
                    8 -> tuv  
                    9 -> wxyz


**Examples**
-Input : "23" -> Output : ["ad ae af bd be bf cd ce cf"]
-Input : "79" -> Output : ["pw px py pz qw qx qy qz rw rx ry rz sw sx sy sz"]
## 🧭 Approach
We will be using the DFS Recursion which is Depth First Search recursion to try all the combinations.

1. Create a mapping of digits to letters.
    mapping[10] = {"", "", "abc", "def", "ghi", "jkl","mno", "pqrs", "tuv", "wxyz"};

2. Defining a recursive function **solve(string digits, int index, string path, vector<string> &result)**
    --> **If** the length of the current combination equals the input digits length, it means we formed a valid combination --> then add to result.
    --> **Else** : 
        - Get the current digit.
        - Loop through all letters mapped to it.
        - And for each letter, append it to the current combination and call the recursive function on the next digit.

3. Edge Case - If input string is empty , return an empty list.

## 🔁 Generic Logic

```code
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
```
## ⏱️ Complexities
    > Time Complexity - O(4ⁿ) , where n is the number of digits in input string. 

    > Space Complexity: O(n × 4ⁿ) 
