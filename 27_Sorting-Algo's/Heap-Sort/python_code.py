def heapify(arr, n, i):
    largest = i
    left = 2 * i
    right = 2 * i + 1

    if left <= n and arr[largest] < arr[left]:
        largest = left
    if right <= n and arr[largest] < arr[right]:
        largest = right

    if largest != i:
        arr[largest], arr[i] = arr[i], arr[largest]
        heapify(arr, n, largest)

def heapSort(arr, n):
    size = n
    while size > 1:
        arr[1], arr[size] = arr[size], arr[1]
        size -= 1
        heapify(arr, size, 1)


n = int(input())
arr = [0]  #  1-based indexing

for _ in range(n):
    arr.append(int(input()))

# Building max heap
for i in range(n // 2, 0, -1):
    heapify(arr, n, i)

print("Printing the array after heapify :: ", end="")
for i in range(1, n + 1):
    print(arr[i], end=" ")

heapSort(arr, n)

print("\nPrinting the sorted array :: ", end="")
for i in range(1, n + 1):
    print(arr[i], end=" ")
