# Python Code

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
