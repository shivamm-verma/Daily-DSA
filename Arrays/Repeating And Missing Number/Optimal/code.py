def findNumbers(nums):
    n = len(nums)
    Sn = n*(n+1)//2
    S2n = n*(n+1)*(2*n+1)//6

    S = sum(nums)
    S2 = sum(x*x for x in nums)

    diff = S - Sn           # x - y
    sqDiff = S2 - S2n       # (x-y)(x+y)

    summ = sqDiff // diff   # x + y

    x = (diff + summ)//2
    y = x - diff

    return x, y

nums = [3,1,2,5,3]
print("Repeating:", findNumbers(nums)[0], "Missing:", findNumbers(nums)[1])
