def findNumbers(nums):
    n = len(nums)
    freq = [0]*(n+1)
    repeating, missing = -1, -1

    for x in nums:
        freq[x] += 1

    for i in range(1,n+1):
        if freq[i] == 0:
            missing = i
        if freq[i] > 1:
            repeating = i
    return repeating, missing

nums = [3,1,2,5,3]
print("Repeating:", findNumbers(nums)[0], "Missing:", findNumbers(nums)[1])
