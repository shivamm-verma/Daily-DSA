# Reverse Nodes in k-Group

### Description
Given the head of a linked list and an integer k, the task is to reverse the nodes of the list in groups of k.
If the number of nodes remaining at the end of thelist is less than k, those nodes should be left in their original order.

Example:
    Input: `1 -> 2 -> 3 -> 4 -> 5`, k = 2
    Output: `2 -> 1 -> 4 -> 3 -> 5`

## Approach 1: Brute-Force
This is the most straightforward method, trading space for simplicity.

Concept:
- Traverse the linked list and copy all its values into an array.

- Reverse the elements within the array in chunks of size k.

- Build a completely new linked list from the modified array.

Complexity:
Time: $$O(N)$$
Space: $$O(N)$$

## Approach 2: Better (Iterative)
This is better because it modifies the list directly without using significant extra memory.

Concept: 
- Iterate through the linked list one group at a time. For each group of k nodes, reverse the pointers "in-place" to reverse the group. This requires carefully managing pointers to link the end of the previous group to the start of the newly reversed group.

Complexity:
Time: $$O(N)$$
Space: $$O(1)$$

## Approach 3: Optimal (Recursive)
This is often considered the most elegant solution due to its concise and clean code structure.

Concept: 
- Use a recursive function that handles one group at a time. The function first checks if there are at least k nodes remaining. If so, it reverses them and then recursively calls itself on the rest of the list. The tail of the current reversed group is then linked to the head of the next reversed group returned by the recursive call.

Complexity:

Time: $$O(N)$$
Space: $$O(N/k)$$ for the recursion call stack.