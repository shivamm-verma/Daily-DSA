# BruteForce.py

def max_subarray_sum_brute(arr):
    n = len(arr)
    max_sum = float('-inf')

    for i in range(n):
        curr_sum = 0
        for j in range(i, n):
            curr_sum += arr[j]
            max_sum = max(max_sum, curr_sum)

    return max_sum

# Example usage
arr = [2, 3, -8, 7, -1, 2, 3]
print("Maximum Subarray Sum (Brute Force):", max_subarray_sum_brute(arr))

# Time Complexity: O(n^2)
# Space Complexity: O(1)
