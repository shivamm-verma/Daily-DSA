def has_triplet_sum(arr, target):
    n = len(arr)

    # Try every triplet combination
    for i in range(n - 2):
        for j in range(i + 1, n - 1):
            for k in range(j + 1, n):
                if arr[i] + arr[j] + arr[k] == target:
                    return True
    return False

# Sample input
arr = [1, 4, 45, 6, 10, 8]
target = 13

# Function call
print("true" if has_triplet_sum(arr, target) else "false")



""" 💡 Notes:
 Time Complexity: O(n³)

 Space Complexity: O(1)

 Simple and easy to understand, good for small input sizes or educational use."""