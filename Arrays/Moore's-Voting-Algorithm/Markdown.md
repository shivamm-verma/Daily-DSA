

 MOORE'S VOTING ALGORITHM - EXPLAINED
===========================================

 Problem:
Find the majority element in an array (if it exists). A **majority element** appears **more than n/2 times** in the array.

 Moore’s Voting Algorithm:
A linear time, constant space algorithm to find the majority element.

 Working Principle:
It works on **cancellation**:
1. Assume the first element is the majority.
2. Use a `count` variable:
   - If the next element is the same, increment `count`.
   - If it’s different, decrement `count`.
   - If `count` becomes zero, pick the next element as a new candidate.
3. After one pass, the potential majority is stored.
4. Do another pass to confirm if it actually occurs more than n/2 times.

 Visualization:
Input: [2, 2, 1, 1, 2, 2, 2]

Pass 1 (finding candidate):
- el = 2, count = 1
- el = 2, count = 2
- el = 1, count = 1
- el = 1, count = 0 (reset)
- el = 2, count = 1
- el = 2, count = 2
- el = 2, count = 3 → candidate is 2

Pass 2 (verifying):
- Count of 2 = 5 > n/2 → Majority element is 2

 Time Complexity: O(n)
 Space Complexity: O(1)

 Use Cases:
 Finding dominant elements in surveys, voting, polling data
 Frequency-based predictions
 Preprocessing in machine learning or data filtering
*/