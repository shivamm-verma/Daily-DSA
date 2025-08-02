## ✅ DSA Question: Spiral Matrix

## 🧠 Problem
Given an m x n matrix, return all elements of the matrix in spiral order.

## Examples:

Input:[[1,2,3], -> Output: [1,2,3,6,9,8,7,4,5]
      [4,5,6],
      [7,8,9]]


Input:[[1,2,3,4], -> Output: [1,2,3,4,8,12,11,10,9,5,6,7]
      [5,6,7,8],
      [9,10,11,12]]


## 🧭 Approach
1. Define four boundaries:
    – top = 0
    – bottom = number of rows - 1
    – left = 0
    – right = number of columns - 1

2. Traverse the matrix in spiral order while top <= bottom and left <= right:

    * Traverse left to right across the top row

    * Traverse top to bottom down the rightmost column

    * Traverse right to left across the bottom row (if still valid)

    * Traverse bottom to top up the leftmost column (if still valid)

    * Update the boundaries after each pass

3. Continue until all elements are added to the result.

## 🔁 Generic Logic (Pseudocode)
```
function spiralOrder(matrix):
    top = 0
    bottom = rows - 1
    left = 0
    right = cols - 1
    result = []

    while top <= bottom and left <= right:
        for i from left to right:
            result.append(matrix[top][i])
        top += 1

        for i from top to bottom:
            result.append(matrix[i][right])
        right -= 1

        if top <= bottom:
            for i from right to left:
                result.append(matrix[bottom][i])
            bottom -= 1

        if left <= right:
            for i from bottom to top:
                result.append(matrix[i][left])
            left += 1

    return result
```

## ⏱️ Complexities
 >Time Complexity
**O(m × n)** — Every element is visited once.

 >Space Complexity
**O(m × n)** — For storing the result (if returned as a new list).