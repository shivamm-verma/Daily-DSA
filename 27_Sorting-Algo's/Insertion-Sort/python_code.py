# function for the insertion sort
def insertion(arr, n):
    for i in range(1, n):
        key = arr[i]
        j = i - 1

        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1

        arr[j + 1] = key


n = int(input("Enter the size of the array: "))
arr = []

print("Enter the elements of the array: ")
for _ in range(n):
    arr.append(int(input()))

insertion(arr, n)

print("\nArray after sorting: ", end="")
for i in arr:
    print(i, end=" ")
print()
