def findNumbers(nums):
    n = len(nums)
    repeating, missing = -1, -1

    for i in range(1, n+1):
        count = nums.count(i)
        if count == 0:
            missing = i
        if count > 1:
            repeating = i
    return repeating, missing

nums = [3,1,2,5,3]
print("Repeating:", findNumbers(nums)[0], "Missing:", findNumbers(nums)[1])
