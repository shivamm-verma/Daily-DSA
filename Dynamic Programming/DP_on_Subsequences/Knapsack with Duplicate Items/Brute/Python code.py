def knapsack(ind, wt, val, capacity):
    if ind == 0:
        return (capacity // wt[0]) * val[0]

    not_take = knapsack(ind - 1, wt, val, capacity)
    take = float('-inf')
    if wt[ind] <= capacity:
        take = val[ind] + knapsack(ind, wt, val, capacity - wt[ind])

    return max(not_take, take)

if __name__ == "__main__":
    val = [6, 1, 7, 7]
    wt = [1, 3, 4, 5]
    capacity = 3
    print(knapsack(len(wt) - 1, wt, val, capacity))
