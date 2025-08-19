🧠 Problem

You are given an array of size n containing numbers from 1 to n.
One number is repeating, and one number is missing.
Find both numbers.

Example
Example 1:

Input: nums = [3,1,2,5,3]  
Output: Repeating = 3, Missing = 4  

---------------------------------------------------

Example 2:

Input: nums = [1,1]  
Output: Repeating = 1, Missing = 2  

Constraints
2 <= n <= 10^5
1 <= nums[i] <= n
Exactly one number is missing and one number is repeating

Approaches
🥉 Brute Force
For each number from 1 to n, count its occurrences in the array.
If frequency = 2 → Repeating.
If frequency = 0 → Missing.

🥈 Better (Hashing)

Use a frequency array or hashmap to track counts of each number.
Traverse nums and increment frequency.
Missing = number with frequency 0.
Repeating = number with frequency > 1.

🥇 Optimal (Mathematical Equations)

Let Sn = n*(n+1)/2 (expected sum of 1…n).
Let S2n = n*(n+1)*(2n+1)/6 (expected sum of squares of 1…n).
Compute actual sums S and S2 from array.

Equations:
S - Sn = x - y (difference between repeating and missing)
S2 - S2n = x² - y² = (x-y)(x+y)
Solve for x (repeating) and y (missing).

Complexities

Brute Force: O(n²) time, O(1) space
Better (Hashing): O(n) time, O(n) space
Optimal (Equations): O(n) time, O(1) space