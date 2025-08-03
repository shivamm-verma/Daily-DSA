def cutRod(price):
    n = len(price)
    prev = [p * price[0] for p in range(n + 1)]

    for i in range(1, n):
        for p in range(n + 1):
            not_take = prev[p]
            take = float('-inf')
            rod_len = i + 1
            if rod_len <= p:
                take = price[i] + prev[p - rod_len]
            prev[p] = max(not_take, take)

    return prev[n]

price = [1, 5, 8, 9, 10, 17, 17, 20]
print(cutRod(price))
