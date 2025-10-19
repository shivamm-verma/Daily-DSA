def sum_zero(n):
    result = []
    for i in range(1, n // 2 + 1):
        result.append(i)
        result.append(-i)
    if n % 2 != 0:
        result.append(0)
    return result

# 👇 User input
n = int(input("Enter the value of n: "))
res = sum_zero(n)
print("Array with sum zero:")
print(res)