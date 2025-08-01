def knapsack(wt, val, capacity, n):
    prev = [0] * (capacity + 1)

    for w in range(capacity + 1):
        prev[w] = (w // wt[0]) * val[0]

    for i in range(1, n):
        for w in range(capacity + 1):
            not_take = prev[w]
            take = float('-inf')
            if wt[i] <= w:
                take = val[i] + prev[w - wt[i]]
            prev[w] = max(not_take, take)

    return prev[capacity]

if __name__ == "__main__":
    val = [6, 1, 7, 7]
    wt = [1, 3, 4, 5]
    capacity = 8
    print(knapsack(wt, val, capacity, len(wt)))
