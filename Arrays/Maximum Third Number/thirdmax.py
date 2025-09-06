def third_max(nums):
    max1 = float('-inf')
    max2 = float('-inf')
    max3 = float('-inf')

    for num in nums:
        if num in (max1, max2, max3):
            continue
        if num > max1:
            max3 = max2
            max2 = max1
            max1 = num
        elif num > max2:
            max3 = max2
            max2 = num
        elif num > max3:
            max3 = num

    return max3 if max3 != float('-inf') else max1

# User input
n = int(input("Enter number of elements: "))
nums = list(map(int, input("Enter the elements separated by space: ").split()))

result = third_max(nums)
print("Third maximum number is:", result)
