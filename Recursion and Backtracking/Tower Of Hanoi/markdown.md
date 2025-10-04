# Tower of Hanoi in Four Languages (Java, C++, Python, JavaScript)

The **Tower of Hanoi** is a classic recursive algorithm that involves moving disks between rods under certain constraints. This document presents its implementation in four different programming languages: Java, C++, Python, and JavaScript.

---

## 🧠 Problem Description

Given three rods and `n` disks of different sizes, the objective is to move all the disks from the source rod to the destination rod following these rules:

1. Only one disk may be moved at a time.
2. Each move consists of taking the upper disk from one of the stacks and placing it on top of another stack.
3. No larger disk may be placed on top of a smaller disk.

---

## ☕ Java Implementation

```java
import java.util.*;

public class TowerOfHanoiExample {

    // Recursive Java function to solve the Tower of Hanoi
    public static void TowerOfHanoi(int n, char src, char dest, char aux) {
        if (n == 1) {
            System.out.println("Move disk 1 from source " + src + " to destination " + dest);
            return;
        }

        TowerOfHanoi(n - 1, src, aux, dest);
        System.out.println("Move disk " + n + " from source " + src + " to destination " + dest);
        TowerOfHanoi(n - 1, aux, dest, src);
    }

    public static void main(String[] args) {
        int n = 4;
        TowerOfHanoi(n, 'A', 'B', 'C');
    }
}

```

## ☕ Cpp Implementation

```cpp
#include <iostream>
using namespace std;

// Recursive C++ function to solve the Tower of Hanoi
void TowerOfHanoi(int n, char src, char dest, char aux) {
    if (n == 1) { // Base Case
        cout << "Move disk 1 from source " << src << " to destination " << dest << endl;
        return;
    }

    TowerOfHanoi(n - 1, src, aux, dest); // Recursive Call 1
    cout << "Move disk " << n << " from source " << src << " to destination " << dest << endl;
    TowerOfHanoi(n - 1, aux, dest, src); // Recursive Call 2
}

// Driver code
int main() {
    int n = 4; // Number of disks
    TowerOfHanoi(n, 'A', 'B', 'C'); // A, B, C are the names of rods
    return 0;
}
```

## ☕ Js Implementation

```js
function towerOfHanoi(n, src, dest, aux) {
    if (n === 1) {
        console.log(`Move disk 1 from source ${src} to destination ${dest}`);
        return;
    }

    towerOfHanoi(n - 1, src, aux, dest);
    console.log(`Move disk ${n} from source ${src} to destination ${dest}`);
    towerOfHanoi(n - 1, aux, dest, src);
}

// Driver code
let n = 4; // Number of disks
towerOfHanoi(n, 'A', 'B', 'C'); // A, B, C are the names of rods

```

## ☕ Python Implementation

```python
def tower_of_hanoi(n, src, dest, aux):
    if n == 1:
        print(f"Move disk 1 from source {src} to destination {dest}")
        return

    tower_of_hanoi(n - 1, src, aux, dest)
    print(f"Move disk {n} from source {src} to destination {dest}")
    tower_of_hanoi(n - 1, aux, dest, src)

# Driver code
n = 4  # Number of disks
tower_of_hanoi(n, 'A', 'B', 'C')  # A, B, C are the names of rods
```
