def threeSum(nums):
    nums.sort()
    lst = []
    for i in range(len(nums) - 2):
        if i > 0 and nums[i] == nums[i - 1]:
            continue
        j = i + 1
        k = len(nums) - 1
        while j < k:
            total = nums[i] + nums[j] + nums[k]
            if total == 0:
                lst.append([nums[i], nums[j], nums[k]])
                j += 1
                k -= 1
                while j < k and nums[j] == nums[j - 1]:
                    j += 1
                while j < k and nums[k] == nums[k + 1]:
                    k -= 1
            elif total > 0:
                k -= 1
            else:
                j += 1
    return lst

if __name__ == "__main__":
    raw_input = input("Enter integers separated by spaces: ")
    nums = list(map(int, raw_input.strip().split()))
    result = threeSum(nums)
    print("\nUnique triplets that sum to zero:")
    for triple in result:
        print(triple)
    
