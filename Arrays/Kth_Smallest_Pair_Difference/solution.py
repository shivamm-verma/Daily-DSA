def smallestDistancePair(nums, k):
    nums.sort()

    def count_pairs(mid):
        count = 0
        left = 0
        for right in range(len(nums)):
            while nums[right] - nums[left] > mid:
                left += 1
            count += right - left
        return count

    left, right = 0, nums[-1] - nums[0]
    while left < right:
        mid = (left + right) // 2
        if count_pairs(mid) >= k:
            right = mid
        else:
            left = mid + 1
    return left


if __name__ == "__main__":
    arr = list(map(int, input("Enter numbers separated by space: ").split()))
    k = int(input("Enter k: "))
    print(smallestDistancePair(arr, k))
