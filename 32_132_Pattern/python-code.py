def find132pattern(nums):
    stack = []
    third = float('-inf')
    for num in reversed(nums):
        if num < third:
            return True
        while stack and num > stack[-1]:
            third = stack.pop()
        stack.append(num)
    return False

n = int(input("Enter number of elements: "))
nums = list(map(int, input("Enter the elements: ").split()))

print("true" if find132pattern(nums) else "false")
