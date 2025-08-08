def transpose(mat):
    rows = len(mat)
    cols = len(mat[0])

    # Create a new matrix with dimensions cols x rows
    result = [[0] * rows for _ in range(cols)]

    # Fill the transposed matrix
    for i in range(rows):
        for j in range(cols):
            result[j][i] = mat[i][j]

    return result

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
Time Complexity: O(n * m)
- We traverse every element once.

Space Complexity: O(n * m)
- We use a new matrix to store the result.
"""
