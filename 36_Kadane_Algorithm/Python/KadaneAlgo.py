

def max_subarray_sum_kadane(arr):
    max_ending_here = arr[0]
    max_so_far = arr[0]

    for i in range(1, len(arr)):
        max_ending_here = max(arr[i], max_ending_here + arr[i])
        max_so_far = max(max_so_far, max_ending_here)

    return max_so_far

# Example usage
arr = [2, 3, -8, 7, -1, 2, 3]
print("Maximum Subarray Sum (Kadane's Algorithm):", max_subarray_sum_kadane(arr))

# Time Complexity: O(n)
# Space Complexity: O(1)
