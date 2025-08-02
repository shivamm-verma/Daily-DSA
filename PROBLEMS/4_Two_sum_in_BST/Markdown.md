##  Two Sum in a BST — Approaches Explained
###  Problem Statement
Given a  `root` of a Binary Search Tree (BST) and an integer `k`, determine if there exist two nodes such that their values add up to `k`.
### 📘 Example

#### Input

```text
BST Elements (level-order input): 10, 5, 15, 3, 7, null, 18  
Target Sum (k): 22
output : True 
The valid pairs are (7,15)
```
#### Visual Diagram
```text
         10
        /  \
       5    15
      / \     \
     3   7     18
```


### 1️⃣ Brute Force Approach (Level Order + Sorting + Two Pointers)
#### Idea
- Traverse the BST in level order and store all node values.

- Sort the list.

- Use two pointers to check if any pair sums up to k.

#### Complexity
- Time: O(n log n) (due to sorting)

- Space: O(n) (storing the values)

#### Code Base
Used in:
✔️ C++ (Level Order)
✔️ Java / Python equivalent provided

### Better Approach (Using Hash Set)
#### Idea
- Perform inorder traversal of the BST to get a sorted array of values.

- Use the two-pointer technique to check if any pair sums to k.


#### Advantage
- No sorting needed.


#### Complexity
- Time: O(n)

- Space: O(n)

#### Code Base
Used in:
✔️ C++ 
✔️ Java 
✔️ Python

#### Optimal Approach (Hash set)
#### Idea
- Use a hash set to store values.

- While traversing the tree, check if the complement k - node->val exists in the set.

- This avoids extra space for sorting and supports early exit.

#### Why Optimal?
No need for hashing or external sort.

#### Complexity
- Time: O(n)

- Space: O(n)

#### Code Base
Used in:
✔️ C++ 
✔️ Java & Python equivalents
