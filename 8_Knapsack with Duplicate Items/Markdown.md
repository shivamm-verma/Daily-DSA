
## 🎒 Unbounded Knapsack Problem — Approaches Explained

## 📘 Problem Statement
Given two integer arrays `wt[]` and `val[]` representing weights and values of n items respectively, and an integer capacity representing a knapsack with limited capacity, determine the maximum total value that can be obtained with unlimited supply of each item.

You can include an item multiple times if it fits.

## 🧪 Example
Input:
    Weights (wt):  [1, 3, 4, 5]  
    Values (val):  [6, 1, 7, 7]  
    Knapsack Capacity: 8  
Output
    Maximum Value: 48  

## Explanation: 
    Choose item with weight 1 and value 6, eight times. (6×8 = 48)

## 1️⃣ Brute Force Recursive Approach (Without Memoization)
## 💡 Idea
* Try all combinations of including or excluding each item.

* At every index, you can:

* Take the item and stay at the same index (ind) (since unbounded).

* Not take the item and move to the previous index (ind - 1).

## ⚙️ Complexity
 >Time: O(2^n) (exponential)

 >Space: O(n) (recursive stack)

## 2️⃣ Top-Down DP (Memoization)
## 💡 Idea
* Add a memoization table `dp[ind][capacity]` to store results of overlapping subproblems.

* Reduces redundant calls.

## ⚙️ Complexity
 >Time: O(n × capacity)

 >Space: O(n × capacity) (for memo table)

## 3️⃣ Bottom-Up DP (Tabulation)
## 💡 Idea
* Use a 2D dp table where `dp[i][w]` is the maximum value for i items and capacity w.

* Start filling the table from base cases.

## ⚙️ Complexity
 >Time: O(n × capacity)

 >Space: O(n × capacity)

## 4️⃣ Space Optimized DP (1D Array)
## 💡 Idea
* Use a 1D array `dp[w]` where each entry keeps track of the max value at that capacity.

* Only one row is required because `dp[i][w]` only depends on `dp[i][w - wt[i]]`.

## ⚙️ Complexity
 >Time: O(n × capacity)

 >Space: O(capacity)
