def cutRod(price, ind, n):
    if ind == 0:
        return n * price[0]
    
    not_take = cutRod(price, ind - 1, n)
    take = float('-inf')
    rod_len = ind + 1
    if rod_len <= n:
        take = price[ind] + cutRod(price, ind, n - rod_len)
    
    return max(take, not_take)

price = [1, 5, 8, 9, 10, 17, 17, 20]
n = len(price)
print(cutRod(price, n - 1, n))
