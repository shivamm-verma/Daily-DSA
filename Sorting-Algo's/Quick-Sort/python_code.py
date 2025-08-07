
def part(arr, low, high):
    pivot = arr[low]
    i = low
    j = high

    while i < j:
        while i <= high - 1 and arr[i] <= pivot:
            i += 1
        while j >= low + 1 and arr[j] > pivot:
            j -= 1
        if i < j:
            arr[i], arr[j] = arr[j], arr[i]

    arr[low], arr[j] = arr[j], arr[low]
    return j

def quickSort(arr, low, high):
    if low < high:
        prevIdx = part(arr, low, high)
        quickSort(arr, low, prevIdx - 1)
        quickSort(arr, prevIdx + 1, high)


n = int(input())
arr = list(map(int, input().split()))

quickSort(arr, 0, n - 1)

for i in arr:
    print(i, end=" ")
