def find_duplicate(nums):
    seen = set()
    for num in nums:
        if num in seen:
            return num
        seen.add(num)
    return -1  

if __name__ == "__main__":
    n = int(input("Enter the number of elements: "))
    print("Enter the elements (space-separated):")
    nums = list(map(int, input().split()))

    if len(nums) != n:
        print("Error: Number of elements doesn't match the specified count.")
    else:
        duplicate = find_duplicate(nums)
        print("Duplicate number is:", duplicate)
