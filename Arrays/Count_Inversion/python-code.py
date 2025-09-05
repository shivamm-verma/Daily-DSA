def merge(arr, temp, left, mid, right):
    i = left      # Left subarray index
    j = mid + 1   # Right subarray index
    k = left      # Temp array index
    inv_count = 0

    while i <= mid and j <= right:
        if arr[i] <= arr[j]:
            temp[k] = arr[i]
            i += 1
        else:
            temp[k] = arr[j]
            inv_count += (mid - i + 1)  # Count inversions
            j += 1
        k += 1

    # Copy remaining elements
    while i <= mid:
        temp[k] = arr[i]
        i += 1
        k += 1

    while j <= right:
        temp[k] = arr[j]
        j += 1
        k += 1

    # Copy back to original array
    for i in range(left, right + 1):
        arr[i] = temp[i]

    return inv_count


def merge_sort(arr, temp, left, right):
    inv_count = 0
    if left < right:
        mid = (left + right) // 2

        inv_count += merge_sort(arr, temp, left, mid)      # Left half
        inv_count += merge_sort(arr, temp, mid + 1, right) # Right half
        inv_count += merge(arr, temp, left, mid, right)    # Merge
    return inv_count


def count_inversions(arr):
    n = len(arr)
    temp = [0] * n
    return merge_sort(arr, temp, 0, n - 1)


# Example usage
if __name__ == "__main__":
    arr = [5, 4, 3, 2, 1]
    print("Array:", arr)
    print("Number of inversions:", count_inversions(arr))
