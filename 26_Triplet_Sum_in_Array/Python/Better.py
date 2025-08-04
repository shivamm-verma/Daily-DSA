def has_triplet_sum(arr, target):
    n = len(arr)

    # Fix the first element
    for i in range(n - 2):
        seen = set()

        # Find the pair in remaining array such that sum = target - arr[i]
        for j in range(i + 1, n):
            required = target - arr[i] - arr[j]

            if required in seen:
                return True

            seen.add(arr[j])

    return False

# Sample input
arr = [1, 4, 45, 6, 10, 8]
target = 13

# Function call
print("true" if has_triplet_sum(arr, target) else "false")


"""💡 Notes:
Time Complexity: O(n²)

Space Complexity: O(n)

Efficient for medium-sized arrays, much faster than brute-force. """