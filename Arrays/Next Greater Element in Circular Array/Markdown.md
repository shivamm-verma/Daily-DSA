📘 Next Greater Element in Circular Array
Problem Statement

Given a circular integer array nums, return the next greater number for every element in the array.
The next greater number of an element x is the first number greater than x as we traverse the array circularly. If it doesn’t exist, return -1.

Example

Input:

nums = [1, 2, 1]


Output:

[2, -1, 2]


Explanation:

For 1 (index 0), the next greater is 2.

For 2 (index 1), no greater element exists → -1.

For 1 (index 2), circularly the next greater is 2.

Approach

Naive Approach (O(n²)):

For each element, loop circularly and check the next greater.

Time-consuming for large arrays.

Optimized Approach (O(n)):

Use a monotonic stack to keep track of elements.

Traverse the array twice (to simulate circular behavior).

For each element, pop smaller elements from stack and assign the current as their next greater.

Python Solution
from typing import List

Complexity Analysis

Time Complexity: O(n) (each element pushed and popped at most once).

Space Complexity: O(n) (stack and result array).
