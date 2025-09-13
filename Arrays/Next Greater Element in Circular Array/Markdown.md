🔄 Next Greater Element in Circular Array
🧠 Problem

Given a circular array, find the Next Greater Element (NGE) for every element

● The Next Greater Element of a number is the first greater number in traversal order.
● Since the array is circular, we wrap around to the start when reaching the end.
● If no greater number exists, return -1.

Examples

● Input: nums = [1, 2, 1]
  Output: [2, -1, 2]

● Input: nums = [5, 4, 3, 2, 1]
  Output: [-1, 5, 5, 5, 5]

🧭 Approach

● Use a monotonic decreasing stack to keep track of indices whose NGE hasn’t been found yet.
● Traverse the array twice (2 * n) to simulate circularity.
● At each step:
  ● While the current number is greater than the stack’s top element, pop it and assign the current number as its NGE.
  ● Push the current index onto the stack if we are still in the first pass.

🔁 Generic Logic (Pseudocode)
function nextGreaterElements(nums):
    n = length(nums)
    result = array of size n filled with -1
    stack = empty stack

    for i from 0 to 2*n - 1:
        current = nums[i % n]
        while stack not empty AND nums[stack.top] < current:
            index = stack.pop()
            result[index] = current
        if i < n:
            stack.push(i)

    return result

⏱️ Complexities

● Time Complexity: O(n)
  ● Each element is pushed and popped at most once.

● Space Complexity: O(n)
  ● Stack stores indices for unresolved elements.