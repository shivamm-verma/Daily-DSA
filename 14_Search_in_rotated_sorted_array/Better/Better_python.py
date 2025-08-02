def find_pivot(nums):
    left, right = 0, len(nums) - 1

    while left < right:
        mid = left + (right - left) // 2

        if nums[mid] > nums[right]:
            left = mid + 1  # Pivot in right half
        else:
            right = mid  # Pivot in left half or at mid

    return left  # Index of smallest element (pivot)

def binary_search(nums, left, right, target):
    while left <= right:
        mid = left + (right - left) // 2

        if nums[mid] == target:
            return mid
        elif nums[mid] < target:
            left = mid + 1
        else:
            right = mid - 1

    return -1

def search(nums, target):
    if not nums:
        return -1

    pivot = find_pivot(nums)

    if nums[pivot] <= target <= nums[-1]:
        return binary_search(nums, pivot, len(nums) - 1, target)  # Right half
    else:
        return binary_search(nums, 0, pivot - 1, target)  # Left half

# Test case
nums = [4, 5, 6, 7, 0, 1, 2]
target = 0
result = search(nums, target)
print(f"Index of target {target}: {result}")  # Output: 4
