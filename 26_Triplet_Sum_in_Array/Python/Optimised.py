def has_triplet_sum(arr, target):
    n = len(arr)
    arr.sort()  # Sort the array first

    # Fix the first element and use two pointers for the remaining part
    for i in range(n - 2):
        left = i + 1
        right = n - 1

        while left < right:
            current_sum = arr[i] + arr[left] + arr[right]

            if current_sum == target:
                return True
            elif current_sum < target:
                left += 1
            else:
                right -= 1

    return False

# Sample input
arr = [1, 4, 45, 6, 10, 8]
target = 13

# Function call
print("true" if has_triplet_sum(arr, target) else "false")

"""  💡 Notes:
Time Complexity: O(n²)

Space Complexity: O(1)

Best approach for large datasets — fast and memory-efficient. """