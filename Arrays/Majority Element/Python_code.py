def majorityElement(nums):
    candidate, count = None, 0
    for num in nums:
        if count == 0:
            candidate = num
        count += 1 if num == candidate else -1
    return candidate

if __name__ == "__main__":
    # Take input
    n = int(input("Enter the size of array: "))
    print("Enter the elements of the array:")
    nums = list(map(int, input().split()))

    if len(nums) != n:
        print("Error: Number of elements does not match the size entered.")
    else:
        # Find majority element
        result = majorityElement(nums)
        print("Majority element:", result)
