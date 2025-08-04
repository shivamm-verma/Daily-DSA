def mysort(arr):
    n = len(arr)
    low = 0         # Index boundary for 0s
    mid = 0         # Current index under consideration
    high = n - 1    # Index boundary for 2s

    while mid <= high:
        if arr[mid] == 0:
            # Swap 0 to the front
            arr[low], arr[mid] = arr[mid], arr[low]
            low += 1
            mid += 1
        elif arr[mid] == 1:
            # 1 is in the right place
            mid += 1
        else:
            # Swap 2 to the end
            arr[mid], arr[high] = arr[high], arr[mid]
            high -= 1


if __name__ == "__main__":
    arr = [0, 1, 2, 0, 1, 2]

    # Apply Dutch Flag sort
    mysort(arr)

    # Output sorted array and *arr unpacks the value in the array
    print("Sorted Array:", *arr)