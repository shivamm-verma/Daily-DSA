# 🧮 DSA QUESTION: The Celebrity Problem

---

## 📝 Problem Statement

A celebrity is a person who is known to all but does not know anyone at a party. A party is being organized by some people. A square matrix `mat[][]` of size `n*n` is used to represent people at the party such that if an element of row i and column j is set to 1 it means ith person knows jth person. You need to return the index of the celebrity in the party, if the celebrity does not exist, return `-1`.

---

## 💡 Example

**Input:**  
mat[][] = [[1, 1, 0],
            [0, 1, 0],
            [0, 1, 1]]

**Output:**  
1

**Explanation:**  
- Person 0 knowns self (0) and 1.
- Person 1 knowns self only.
- Person 2 knowns 1 and self (2).
- Therefore, everyone knowns person 1.


---

## ✅ Constraints

- `1 ≤ mat.size() ≤ 1000`
- `0 ≤ mat[i][j] ≤ 1`
- `mat[i][i] = 1`

---

## Approach 1: Brute Force method

- Initialize matrix size `n` as total number of people.
- For each person `i`, we set flags - `knownsSomeone = false` and `knownByEveryone = true`.
- Run an inner loop for all persons `j`.
  - If person `i` knows `j`, then set `knowsSomeone = true`.
  - If person `j` does not know `i`, then set `knownByEveryone = false`.
- If `!knowsSomeone && knownByEveryone` then person `i` is the celebrity and return `i`.
- Else return `-1` if no celebrity found.
  
### Time and Space Complexity:-
- Time Complexity: O(n^2)
- Space Complexity: O(1)

---

## Approach 2: Better Solution - Using Stack

- Initialize a stack and push all `n` people into the stack.
- While the stack has more than one person, pop two individuals `a` and `b`. If `a` knows `b`, then `a` cannot be the celebrity, so push `b` back. Otherwise, `b` cannot be the celebrity, so push `a` back.
- After the loop, one person that remains in the stack is the potential celebrity.
- For every person `i ≠ candidate`, check two conditions
  - if the candidate knows `i` 
  - if `i` does not know the candidate, then the candidate is not a celebrity.
- Return the candidate index if all checks pass.
  
### Time and Space Complexity:-
- Time Complexity: O(n)
- Space Complexity: O(n)

---

## Approach 3: Optimal Solution

- We start with `candidate = 0`. 
- For each person `i` from `1` to `n-1`, if candidate knows i, then candidate cannot be the celebrity so, `candidate = i`.
- If any person `i ≠ candidate` is not aware of the candidate or the candidate is aware of `i`, then the candidate fails the celebrity test and `-1` is returned.
- If all checks pass, return the candidate as the celebrity.
  
  
### Time and Space Complexity:-
- Time Complexity: O(n)
- Space Complexity: O(1)