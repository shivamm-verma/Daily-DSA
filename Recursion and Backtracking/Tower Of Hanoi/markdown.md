## ✅ DSA Question: Tower of Hanoi

---

### 🧠 Problem  
Given three rods and n disks of different sizes, the objective is to move all the disks from the source rod to the destination rod, using the auxiliary rod, following these constraints:

Only one disk may be moved at a time.

Each move consists of taking the upper disk from one of the stacks and placing it on top of another stack.

No larger disk may be placed on top of a smaller disk.

**Examples:** 

For n = 3, the steps to move disks from Rod A to Rod C using Rod B would follow the recursive pattern:
Move 2 disks to auxiliary
Move bottom disk to destination
Move 2 disks from auxiliary to destination


## 🧭 Approach

1. If there's only one disk, move it directly from source to destination.

2. Otherwise:

    – Move n-1 disks from source to auxiliary rod.  
    – Move the remaining disk to destination rod.

---

## 🔁 Generic Logic (Pseudocode)
```plaintext
function towerOfHanoi(n, source, destination, auxiliary):
    if n == 1:
        print "Move disk 1 from", source, "to", destination
        return

    towerOfHanoi(n - 1, source, auxiliary, destination)
    print "Move disk", n, "from", source, "to", destination
    towerOfHanoi(n - 1, auxiliary, destination, source)
```

## ⏱️ Complexities
 > Time Complexity
**O(2ⁿ - 1)** — Exponential; each call spawns two more for n-1 disks.

> Space Complexity
**O(n)** — Recursion stack depth is proportional to number of disks.