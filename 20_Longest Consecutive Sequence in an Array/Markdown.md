Longest Consecutive Sequence in an Array -Explained
====================================================


Given an array nums of n integers.

Return the length of the longest sequence of consecutive integers. The integers in this sequence can appear in any order.

## Examples:
Input: nums = [100, 4, 200, 1, 3, 2]

Output: 4

# Explanation:

The longest sequence of consecutive elements in the array is [1, 2, 3, 4], which has a length of 4. This sequence can be formed regardless of the initial order of the elements in the array.

# Input: nums = [0, 3, 7, 2, 5, 8, 4, 6, 0, 1]

Output: 9

# Explanation:

The longest sequence of consecutive elements in the array is [0, 1, 2, 3, 4, 5, 6, 7, 8], which has a length of 9. 

Input: nums = [1, 9, 3, 10, 4, 20, 2]

Output:
4

### BRUTE FORCE APPROACH 

# Intuition
One simple approach is to look for sequences of consecutive numbers by utilising linear search in the array. For each number 𝑥 in the array, we'll check if the next numbers like 𝑥+1, 𝑥+2, 𝑥+3, and so on, are also in the array. This is like checking if we can build a chain of numbers that follow each other directly. By doing this for every number in the array, we can find the longest chain of consecutive numbers. Finally, we'll find the length of the longest chain among all the numbers in the array.

# Approach
As you iterate through each number in the array, begin by checking if consecutive numbers like ( x+1, x+2, x+3 ), and so on, exist in the array. The occurrence of the next consecutive number can be checked by using linear search.
When you find consecutive numbers, start counting them using a counter. Increment this counter each time you find the next consecutive number in the sequence.
This counter effectively keeps track of how long the current consecutive sequence is as you move through the array and find more consecutive numbers.

# Complexity Analysis:
Time Complexity: O(N3), where N is the size of the array.
In the worst case, all N elements form a single consecutive sequence. Each element in nums is checked in the outer loop O(N) times. The inner while loop could also run O(N) times for one outer iteration. Since linearSearch() is called inside the conditional statement of the while loop and itself runs in O(N), this results in a cubic time complexity.

Space Complexity: O(1), as we are not using any extra space to solve this problem.


### OPTIMAL APPROACH

# Intuition
In this approach, we refine the brute-force method by focusing only on potential starting numbers of sequences, rather than searching for sequences for every array element. This targeted strategy enhances efficiency using a Set data structure.

# Approach
We will use two variables, cnt to store the length of the current sequence and longest to store the maximum length found.

First, all array elements are placed into a set data structure.

For each element x that can start a sequence (i.e., x - 1 does not exist in the set) we follow the below steps:

Initialize cnt to 1, indicating the starting element of a new sequence.
Utilize the set to search for consecutive elements such as x + 1, x + 2, and so on, to determine the maximum possible length of the current sequence. Update cnt accordingly.
Compare cnt with longest and update longest to hold the maximum value (longest = max(longest, cnt)).
Finally, longest will contain the length of the longest consecutive sequence found in the array.

# Complexity Analysis 
Time Complexity: O(N) + O(2xN) ~ O(3xN), where N is the size of the array. The function takes O(N) to insert all elements into the set data structure. After that, for every starting element, we find the consecutive elements. Although nested loops are used, the set will be traversed at most twice in the worst case. Therefore, the time complexity is O(2xN) instead of O(N2).

# Space Complexity: O(N), as we use a set data structure to solve this problem.
Note: The time complexity assumes that we use an unordered_set, which has O(1) time complexity for set operations.

In the worst case, if the set operations take O(N), the total time complexity would be approximately O(N2). If we use a set instead of an unordered_set, the set operations will have a time complexity of O(logN), resulting in a total time complexity of O(NlogN).