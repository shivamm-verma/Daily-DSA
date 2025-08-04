# ❓ Problem: Set Matrix Zeroes

Given an `m x n` integer matrix, if an element is `0`, set its **entire row and column** to `0` in-place.

---

### 📌 Example

**Input:**
matrix = [
[1, 2, 3],
[4, 0, 6],
[7, 8, 9]
]
**Output:**
[
[1, 0, 3],
[0, 0, 0],
[7, 0, 9]
]

---

## ✅ Brute Force Approach

### 🔍 Intuition
We traverse the matrix and **mark cells that need to be set to zero** using a placeholder value like `-1` (assuming `-1` doesn't already exist in the matrix). After marking, we go for a second pass to update all `-1` cells to `0`.

### 🧠 Explanation
1. Traverse the matrix.
2. If `matrix[i][j] == 0`, mark all `matrix[i][k]` and `matrix[k][j]` as `-1` (except if it's already `0`).
3. Do a second traversal to convert all `-1` to `0`.

### ⏱ Time Complexity:
O(m × n × (m + n)) — worst case for each zero, marking the row and column.

### 📦 Space Complexity:
O(1) — only using in-place marking.

---

## ✅ Better Approach

### 🔍 Intuition
Instead of marking in-place, maintain two arrays to **record which rows and columns** should be made zero.

### 🧠 Explanation
1. Create two arrays: `row[m]` and `col[n]` to track the zeros.
2. In the first pass, if `matrix[i][j] == 0`, mark `row[i] = 1` and `col[j] = 1`.
3. In the second pass, if `row[i] == 1` or `col[j] == 1`, set `matrix[i][j] = 0`.

### ⏱ Time Complexity:
O(m × n)

### 📦 Space Complexity:
O(m + n)

---

## ✅ Optimal Approach

### 🔍 Intuition
Use the **first row and column of the matrix itself as the markers** to avoid extra space.

### 🧠 Explanation
1. Use `matrix[0][j]` to mark columns, and `matrix[i][0]` to mark rows.
2. Use a **separate flag for the first column** (since `matrix[0][0]` overlaps).
3. First pass: mark the rows/columns.
4. Second pass (reverse direction): update elements based on markers.

---
## Code

Brute

### Java
```java

import java.util.Scanner;

public class soln{

    public static void setMatrixZero(int[][] matrix, int rows, int cols) {
        int marker = -999999;

        // First pass: mark rows and columns
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == 0) {
                    // Mark row
                    for (int k = 0; k < cols; k++) {
                        if (matrix[i][k] != 0)
                            matrix[i][k] = marker;
                    }
                    // Mark column
                    for (int k = 0; k < rows; k++) {
                        if (matrix[k][j] != 0)
                            matrix[k][j] = marker;
                    }
                }
            }
        }

        // Second pass: replace marker with 0
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == marker) {
                    matrix[i][j] = 0;
                }
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of rows: ");
        int rows = sc.nextInt();

        System.out.print("Enter number of columns: ");
        int cols = sc.nextInt();

        int[][] matrix = new int[rows][cols];
        System.out.println("Enter matrix elements:");

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                matrix[i][j] = sc.nextInt();
            }
        }

        setMatrixZero(matrix, rows, cols);

        System.out.println("\nMatrix after setting zeroes:");
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                System.out.print(matrix[i][j] + " ");
            }
            System.out.println();
        }

        sc.close();
    }
}
```

### Python
```python

def set_matrix_zero(matrix):
    rows = len(matrix)
    cols = len(matrix[0])
    marker = -999999

    # First pass: mark
    for i in range(rows):
        for j in range(cols):
            if matrix[i][j] == 0:
                # Mark row
                for k in range(cols):
                    if matrix[i][k] != 0:
                        matrix[i][k] = marker
                # Mark column
                for k in range(rows):
                    if matrix[k][j] != 0:
                        matrix[k][j] = marker

    # Second pass: replace marker with 0
    for i in range(rows):
        for j in range(cols):
            if matrix[i][j] == marker:
                matrix[i][j] = 0


# Input and testing
rows = int(input("Enter number of rows: "))
cols = int(input("Enter number of columns: "))

matrix = []
print("Enter matrix elements row-wise:")
for _ in range(rows):
    matrix.append(list(map(int, input().split())))

print("\nOriginal Matrix:")
for row in matrix:
    print(" ".join(map(str, row)))

set_matrix_zero(matrix)

print("\nMatrix after setting zeroes:")
for row in matrix:
    print(" ".join(map(str, row)))

```

### C++
```cpp
// C++ Code

#include <iostream>
using namespace std;

void setMatrixZero(int matrix[][100], int rows, int cols) {
    int marker = -999999;

    // First pass: mark rows and columns with the marker
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 0) {
                // Mark the entire row
                for (int k = 0; k < cols; k++) {
                    if (matrix[i][k] != 0)
                        matrix[i][k] = marker;
                }
                // Mark the entire column
                for (int k = 0; k < rows; k++) {
                    if (matrix[k][j] != 0)
                        matrix[k][j] = marker;
                }
            }
        }
    }

    // Second pass: convert marker to 0
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == marker)
                matrix[i][j] = 0;
        }
    }
}

int main() {
    int matrix[100][100];
    int rows, cols;

    cout << "Enter rows and columns: ";
    cin >> rows >> cols;

    cout << "Enter matrix elements:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    setMatrixZero(matrix, rows, cols);

    cout << "\nMatrix after setting zeroes:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
```

---
Better
### Java
```java
// Java Code

import java.util.Scanner;

public class soln2 {

    public static void setMatrixZero(int[][] matrix, int rows, int cols) {
        int[] row = new int[rows];
        int[] col = new int[cols];

        // Mark rows and columns that should be zeroed
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == 0) {
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }

        // Set matrix[i][j] = 0 if its row or column is marked
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (row[i] == 1 || col[j] == 1) {
                    matrix[i][j] = 0;
                }
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of rows: ");
        int rows = sc.nextInt();

        System.out.print("Enter number of columns: ");
        int cols = sc.nextInt();

        int[][] matrix = new int[rows][cols];
        System.out.println("Enter matrix elements:");

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                matrix[i][j] = sc.nextInt();
            }
        }

        setMatrixZero(matrix, rows, cols);

        System.out.println("\nMatrix after setting zeroes:");
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                System.out.print(matrix[i][j] + " ");
            }
            System.out.println();
        }

        sc.close();
    }
}

```

### Python
```python
# Python Code

def set_matrix_zero(matrix):
    rows = len(matrix)
    cols = len(matrix[0])
    
    row = [0] * rows
    col = [0] * cols

    # First pass: mark rows and columns
    for i in range(rows):
        for j in range(cols):
            if matrix[i][j] == 0:
                row[i] = 1
                col[j] = 1

    # Second pass: set to 0 if marked
    for i in range(rows):
        for j in range(cols):
            if row[i] == 1 or col[j] == 1:
                matrix[i][j] = 0


# Input
rows = int(input("Enter number of rows: "))
cols = int(input("Enter number of columns: "))

matrix = []
print("Enter matrix elements row-wise:")
for _ in range(rows):
    matrix.append(list(map(int, input().split())))

print("\nOriginal Matrix:")
for row in matrix:
    print(" ".join(map(str, row)))

set_matrix_zero(matrix)

print("\nMatrix after setting zeroes:")
for row in matrix:
    print(" ".join(map(str, row)))

```

### C++
```cpp
// C++ Code

#include <iostream>
using namespace std;

void setMatrixZero(int matrix[][100], int rows, int cols) {
    int row[100] = {0};
    int col[100] = {0};

    // Mark rows and columns that contain 0
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 0) {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    // Set zeroes based on row[] and col[]
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (row[i] == 1 || col[j] == 1) {
                matrix[i][j] = 0;
            }
        }
    }
}

int main() {
    int matrix[100][100];
    int rows, cols;

    cout << "Enter rows and columns: ";
    cin >> rows >> cols;

    cout << "Enter matrix elements:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    setMatrixZero(matrix, rows, cols);

    cout << "\nMatrix after setting zeroes:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
```
---
Optimal

### Java 
```java
// Java Code

import java.util.Scanner;

public class soln3 {

    public static void setMatrixZero(int[][] matrix, int rows, int cols) {
        boolean firstRow = false, firstCol = false;

        // Check if first row has any zero
        for (int j = 0; j < cols; j++) {
            if (matrix[0][j] == 0) {
                firstRow = true;
                break;
            }
        }

        // Check if first column has any zero
        for (int i = 0; i < rows; i++) {
            if (matrix[i][0] == 0) {
                firstCol = true;
                break;
            }
        }

        // Use first row and column as markers
        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < cols; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Set matrix cells to zero based on markers
        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < cols; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Update first row if needed
        if (firstRow) {
            for (int j = 0; j < cols; j++) {
                matrix[0][j] = 0;
            }
        }

        // Update first column if needed
        if (firstCol) {
            for (int i = 0; i < rows; i++) {
                matrix[i][0] = 0;
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of rows: ");
        int rows = sc.nextInt();
        System.out.print("Enter number of columns: ");
        int cols = sc.nextInt();

        int[][] matrix = new int[rows][cols];
        System.out.println("Enter matrix elements:");
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                matrix[i][j] = sc.nextInt();
            }
        }

        setMatrixZero(matrix, rows, cols);

        System.out.println("\nMatrix after setting zeroes:");
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                System.out.print(matrix[i][j] + " ");
            }
            System.out.println();
        }

        sc.close();
    }
}

```

### Python
```python
# Python Code

def set_matrix_zero(matrix):
    rows = len(matrix)
    cols = len(matrix[0])
    first_row = any(matrix[0][j] == 0 for j in range(cols))
    first_col = any(matrix[i][0] == 0 for i in range(rows))

    # Use first row and column as markers
    for i in range(1, rows):
        for j in range(1, cols):
            if matrix[i][j] == 0:
                matrix[i][0] = 0
                matrix[0][j] = 0

    # Set matrix[i][j] = 0 if its row or column is marked
    for i in range(1, rows):
        for j in range(1, cols):
            if matrix[i][0] == 0 or matrix[0][j] == 0:
                matrix[i][j] = 0

    # Update first row
    if first_row:
        for j in range(cols):
            matrix[0][j] = 0

    # Update first column
    if first_col:
        for i in range(rows):
            matrix[i][0] = 0

# Input
rows = int(input("Enter number of rows: "))
cols = int(input("Enter number of columns: "))

matrix = []
print("Enter matrix elements row-wise:")
for _ in range(rows):
    matrix.append(list(map(int, input().split())))

print("\nOriginal Matrix:")
for row in matrix:
    print(" ".join(map(str, row)))

set_matrix_zero(matrix)

print("\nMatrix after setting zeroes:")
for row in matrix:
    print(" ".join(map(str, row)))

```


### C++
```cpp
// C++ Code

#include <iostream>
using namespace std;

void setMatrixZero(int matrix[][100], int rows, int cols) {
    bool firstRow = false, firstCol = false;

    // Check if first column has any zero
    for (int i = 0; i < rows; i++) {
        if (matrix[i][0] == 0)
            firstCol = true;
    }

    // Check if first row has any zero
    for (int j = 0; j < cols; j++) {
        if (matrix[0][j] == 0)
            firstRow = true;
    }

    // Use first row and column as markers
    for (int i = 1; i < rows; i++) {
        for (int j = 1; j < cols; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    // Set zeroes based on markers
    for (int i = 1; i < rows; i++) {
        for (int j = 1; j < cols; j++) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;
        }
    }

    // Update first row if needed
    if (firstRow) {
        for (int j = 0; j < cols; j++)
            matrix[0][j] = 0;
    }

    // Update first column if needed
    if (firstCol) {
        for (int i = 0; i < rows; i++)
            matrix[i][0] = 0;
    }
}

int main() {
    int matrix[100][100];
    int rows, cols;

    cout << "Enter rows and columns: ";
    cin >> rows >> cols;

    cout << "Enter matrix elements:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    setMatrixZero(matrix, rows, cols);

    cout << "\nMatrix after setting zeroes:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

```

---



### ⏱ Time Complexity:
O(m × n)

### 📦 Space Complexity:
O(1) — done in-place with no extra space.