def countAtMostK(nums, k):
    left = 0
    count = 0
    odd = 0

    for right in range(len(nums)):
        if nums[right] % 2 == 1:
            odd += 1
        while odd > k:
            if nums[left] % 2 == 1:
                odd -= 1
            left += 1
        count += right - left + 1
    return count

def numberOfSubarrays(nums, k):
    return countAtMostK(nums, k) - countAtMostK(nums, k - 1)
