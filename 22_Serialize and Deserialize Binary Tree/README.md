# Title: Serialize and Deserialize Binary Tree

### Description: 
**Serialization** is the process of converting a data structure, like a binary tree, into a format that can be easily stored (e.g., in a file).
**Deserialization** is the reverse process: reconstructing the original data structure from the serialized format.

The goal is to design an algorithm to reliably serialize a binary tree into a single string and deserialize that string back into an identical binary tree structure.


## Approach 1: Brute-Force (Using Two Traversals)
A less direct method that relies on classic tree reconstruction algorithms.

- Concept: Serialize the tree into two separate strings: one using pre-order traversal and one using in-order traversal. To deserialize, use the pre-order string to identify the root of each subtree and the in-order string to partition which nodes belong to the left and right children.

Complexity:
Time: O(N)
Space: O(N)

## Approach 2: Optimal DFS (Pre-order Traversal)
This is a common and efficient approach that uses a single traversal to preserve the tree's structure.

- Concept: Perform a single pre-order (DFS) traversal. When visiting a node, append its value to the string. If a child is null, append a marker (e.g., #). This creates a compact string that can be easily deserialized recursively.

Complexity:
Time: O(N)
Space: O(N)

## Approach 3: Optimal BFS (Level-order Traversal)
This is another efficient approach that avoids deep recursion by processing the tree level by level.

- Concept: Perform a level-order (BFS) traversal using a queue. Iterate through the tree one level at a time, appending each node's value or a null marker (#) to the string. Deserialization reconstructs the tree level by level, also using a queue.

Complexity:
Time: O(N)
Space: O(N)