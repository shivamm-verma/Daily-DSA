def search(nums, target):
    # Linear search through the array
    for i in range(len(nums)):
        if nums[i] == target:
            return i
    return -1  # Target not found

# Test case
nums = [4, 5, 6, 7, 0, 1, 2]
target = 0
result = search(nums, target)
print(f"Index of target {target}: {result}")  # Output: 4
