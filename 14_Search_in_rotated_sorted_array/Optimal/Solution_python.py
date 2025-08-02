def search(nums, target):
    left, right = 0, len(nums) - 1

    while left <= right:
        mid = left + (right - left) // 2

        if nums[mid] == target:
            return mid

        # Check if left half is sorted
        if nums[left] <= nums[mid]:
            if nums[left] <= target < nums[mid]:
                right = mid - 1  # target in left half
            else:
                left = mid + 1  # target in right half
        else:
            # Right half is sorted
            if nums[mid] < target <= nums[right]:
                left = mid + 1  # target in right half
            else:
                right = mid - 1  # target in left half

    return -1  # Target not found

# Test case
nums = [4, 5, 6, 7, 0, 1, 2]
target = 0
result = search(nums, target)
print(f"Index of target {target}: {result}")  # Output: 4
