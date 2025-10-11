
# Function to count the number of pairs with difference <= mid
def count_pairs(nums, mid):
    count = 0
    left = 0
    for right in range(len(nums)):
        while nums[right] - nums[left] > mid:
            left += 1
        count += right - left
    return count

# Function to find Kth smallest pair difference
def smallestDistancePair(nums, k):
    """
    Approach:
    1. Sort the array
    2. Use binary search on the possible difference values (0 to max-min)
    3. For each mid, count pairs with difference <= mid using two pointers
    4. Narrow the search space based on the count

    Time Complexity: O(n log W), where W = max(nums) - min(nums)
    Space Complexity: O(1)
    """
    nums.sort()
    left, right = 0, nums[-1] - nums[0]
    
    while left < right:
        mid = (left + right) // 2
        if count_pairs(nums, mid) >= k:
            right = mid
        else:
            left = mid + 1
    return left

if __name__ == "__main__":
    # Interactive input
    arr = list(map(int, input("Enter numbers separated by space: ").split()))
    k = int(input("Enter k: "))
    print("Kth Smallest Pair Difference:", smallestDistancePair(arr, k))
