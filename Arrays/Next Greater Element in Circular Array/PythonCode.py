def nextGreaterElements(nums):
    n = len(nums)
    res = [-1] * n
    stack = []  # store indices

    # Traverse twice to simulate circular array
    for i in range(2 * n):
        curr = nums[i % n]
        while stack and nums[stack[-1]] < curr:
            res[stack.pop()] = curr
        if i < n:  # only push first n elements
            stack.append(i)
    return res