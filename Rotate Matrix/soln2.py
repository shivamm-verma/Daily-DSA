def rotate(matrix):
    N = len(matrix)

    for i in range(N):
        for j in range(i, N):
            matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]

    for row in matrix:
        row.reverse()

def print_matrix(matrix):
    for row in matrix:
        print(" ".join(map(str, row)))

matrix = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9]
]

print("Original Matrix:")
print_matrix(matrix)

rotate(matrix)

print("\nRotated Matrix:")
print_matrix(matrix)
