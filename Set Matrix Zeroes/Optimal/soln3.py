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
