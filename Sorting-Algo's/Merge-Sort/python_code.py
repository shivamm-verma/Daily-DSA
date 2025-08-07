
def mergeSort(arr, low, mid, high):
    temp = []
    left = low
    right = mid + 1

    while left <= mid and right <= high:
        if arr[left] <= arr[right]:
            temp.append(arr[left])
            left += 1
        else:
            temp.append(arr[right])
            right += 1

    while left <= mid:
        temp.append(arr[left])
        left += 1

    while right <= high:
        temp.append(arr[right])
        right += 1

    for i in range(low, high + 1):
        arr[i] = temp[i - low]


def merge(arr, low, high):
    if low >= high:
        return

    mid = (low + high) // 2
    merge(arr, low, mid)
    merge(arr, mid + 1, high)
    mergeSort(arr, low, mid, high)



n = int(input("Enter the size of the array: "))
arr = []

print("Enter the elements of the array: ")
for _ in range(n):
    arr.append(int(input()))

merge(arr, 0, n - 1)

print("\nArray after sorting: ", end="")
for i in arr:
    print(i, end=" ")
print()
