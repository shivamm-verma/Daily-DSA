def transpose(mat):
    n = len(mat)  # Square matrix assumed

    # Swap elements across the main diagonal
    for i in range(n):
        for j in range(i + 1, n):
            mat[i][j], mat[j][i] = mat[j][i], mat[i][j]

    return mat

# Example usage
mat = [
    [1, 1, 1, 1],
    [2, 2, 2, 2],
    [3, 3, 3, 3],
    [4, 4, 4, 4]
]

res = transpose(mat)

# Print result
for row in res:
    print(row)

"""
Time Complexity: O(n^2)
- We iterate over the upper triangle of the square matrix.

Space Complexity: O(1)
- In-place transpose, so no extra space is used.
- Works only for square matrices.
"""
