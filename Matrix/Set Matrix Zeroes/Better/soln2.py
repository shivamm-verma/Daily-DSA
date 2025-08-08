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
