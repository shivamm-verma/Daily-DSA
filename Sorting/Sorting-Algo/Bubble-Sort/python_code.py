
#  function for bubble sort
def bubble(arr, n):
    for i in range(n - 1):
        for j in range(n - i - 1):
            if arr[j] > arr[j + 1]:
                # Swap
                arr[j], arr[j + 1] = arr[j + 1], arr[j]

#  code to test function
n = int(input("Enter the size of an array :: "))
arr = []

print("Enter the elements of the array :: ")
for _ in range(n):
    arr.append(int(input()))

bubble(arr, n)

print("\nAfter sorting array :: ")
for i in arr:
    print(i, end=" ")
print()
