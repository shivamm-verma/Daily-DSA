#  function for the selection sort
def selection(arr, n):
    for i in range(n - 1):
        min = i
        for j in range(i + 1, n):
            if arr[j] < arr[min]:
                min = j
        if min != i:
            arr[i], arr[min] = arr[min], arr[i]


n = int(input("Enter the size of an array :: "))
arr = []

print("Enter the elements of the array :: ")
for _ in range(n):
    arr.append(int(input()))

selection(arr, n)

print("\nAfter sorting array :: ")
for i in arr:
    print(i, end=" ")
print()
