def max_product(arr):
    curr_max = arr[0]
    curr_min = arr[0]
    maxp = arr[0]

    for i in range(1, len(arr)):
        temp = max(arr[i], arr[i] * curr_max, arr[i] * curr_min)
        curr_min = min(arr[i], arr[i] * curr_max, arr[i] * curr_min)
        curr_max = temp
        maxp = max(maxp, curr_max)
    return maxp

if __name__ == "__main__":
    n = int(input())
    arr = list(map(int, input().split()))
    result = max_product(arr)
    print(result)
